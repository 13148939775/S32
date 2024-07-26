/*
 * @author 007313 008196
 * @for Can Data handler trategy, storage file and upload
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "can_data_handler.h"

#include <string>

#include <node_log.h>

#include "RecoderHandler.h"
#include "AdcmDataFileCtrl.h"
#include "dumper/DataDumper.h"
#include "trigger/TriggerManager.h"

#include "HhtLooperThread.h"
#include "HhtTaskLooper.h"
#include "PathTool.h"

#include "DataUploader.h"

namespace HHT {
namespace DataManager {

// TODO: add to config?
static constexpr uint32_t UPLOADER_RETRY_MAX_COUNT = 4;
static constexpr uint32_t UPLOADER_RETRY_INTERVAL_MS = 5 * 1000;     // 5S
static constexpr uint32_t DATA_UPLOAD_RETRY_INTERVAL_MS = 5 * 1000;  // 5S

class CanDataHandler::Impl : public DataUploader::DataUploaderCallbackIF {
public:
    Impl(const CanDataHandler& owner, const RecoderHandler& recoder);   // ??
    ~Impl();

    // Run in workThread
    //void activate();
    //void deactivate();
    //void onSn(std::string sn);
    void onPowerSwitch(bool isDown);
    void onUploaderInited(bool success);
    //void doUpload();

    // Run in user thread
    void HandleData(const DataInfo& info, uint8_t* data, size_t len);

public:
    // IF for DataUploader::DataUploaderCallbackIF
    void onInited(DataUploader::ErrorCode errorCode) override;
    void onUploaded(DataUploader::DataType type, const std::string& fileOrName,
                    DataUploader::ErrorCode errorCode) override;
    void onFetchLogRule(uint64_t timestamp, const std::string& jsonFule) override;

    // IF for Dumper
    void onDump(const DumpInfo& info);
    void onConfirm(const DumpHeader& header);

public:
    enum UploadTask {
        UploadData,
        UploadDesc
    };
    enum UploadState {
        NoUpload,
        Uploading,
        UploadFailed,
        UploadDone
    };
    struct UploadContext {
        std::string name;
        UploadTask task;
        UploadState state;
        uint32_t retryCount;

        UploadContext(const std::string& _name, UploadTask _task, UploadState _state)
            : name(_name), task(_task), state(_state), retryCount(0) { }
        UploadContext(): UploadContext(std::string(), UploadData, NoUpload) { }
    };

    class CanDumperWorkerIF : public DumperWorkerIF {  // save to local file
    public:
        CanDumperWorkerIF(CanDataHandler::Impl& handler) : mHandler(handler) { }
        void onRequestDump(DumpInfo info) override 
        {
            mHandler.onDump(info);
        }
        void onRequestConfirm(DumpHeader header) override 
        {
            mHandler.onConfirm(header);
        }
    private:
        CanDataHandler::Impl& mHandler;
    };

public:
    CanDataHandler& owner_;
    RecoderHandler& mRecoder;
    LooperThread mWorkThread;
    TriggerManager mTriggerMgr;
    DataUploader uploader_;
    std::string mSn;
    bool mUploaderReady;
    uint32_t mUploaderRetryTimes;
    AdcmDataFileCtrl fileCtrl_;
    UploadContext mUploadCxt;
    DataDumper dumper_;
    CanDumperWorkerIF dumperWorker_;
};

CanDataHandler::Impl::Impl(const CanDataHandler& owner, const RecoderHandler& recoder)
    : owner_(owner),
      mRecoder(recoder),
      mWorkThread(),
      mTriggerMgr(),
      uploader_(*this),
      mSn(),
      mUploaderReady(false),
      mUploaderRetryTimes(0),
      fileCtrl_(owner),
      mUploadCxt(),
      dumper_(),
      dumperWorker_(*this) { }

CanDataHandler::Impl::~Impl() { }

inline uint64_t timestampGen(std::string name) {
    int64_t timestamp = atoll(name.c_str()) / 1000;
    if (0 > timestamp) {
        return 0;
    }
    return timestamp;
}

void CanDataHandler::Impl::activate() 
{
    fileCtrl_.activate();

    owner_.onActivated(true, ErrorCode::OK);
    if (!mSn.empty() && 0 == mUploaderRetryTimes) {  // TODO: logic
        ++mUploaderRetryTimes;
        uploader_.Init(mSn);
    }
}

void CanDataHandler::Impl::deactivate() {
    fileCtrl_.deactivate();
    owner_.onActivated(false, ErrorCode::OK);
}

void CanDataHandler::Impl::onSn(std::string sn) {
    // TODO:
    mSn = sn;
    if (owner_.isActivated() && 0 == mUploaderRetryTimes) {
        ++mUploaderRetryTimes;
        uploader_.Init(mSn);
    }
}

void CanDataHandler::Impl::OnPowerSwitch(bool isDown) {
    if (owner_.isActivated()) {
        fileCtrl_.preventIoAccess(isDown);
        uploader_.powerDown(isDown);
    }
}

void CanDataHandler::Impl::HandleData(const DataInfo& info, uint8_t* data, size_t len) 
{
    //if ((owner_.isActivated() && (info.dtype == Structured)) {
        mTriggerMgr.triggerUpdateHandler(info.stInfo.topic, data, len);
        dumper_.sendData(info.stInfo.topic, data, len);  // ready to save file then upload
    //}
}

void CanDataHandler::Impl::onUploaderInited(bool success) {
    mUploaderReady = success;
    if (!mUploaderReady) {
        ++mUploaderRetryTimes;
        LOG(ERROR) << "onUploaderInited: Init DataUploader failed. times: " << mUploaderRetryTimes;
        if (mUploaderRetryTimes <= UPLOADER_RETRY_MAX_COUNT) {
            mWorkThread.looper().postDelayTask(std::bind(&DataUploader::Init, &uploader_, mSn), UPLOADER_RETRY_INTERVAL_MS);
        } else {
            LOG(ERROR) << "onUploaderInited: Init DataUploader failed too many times, stop retry!!";
        }
        return;
    }
    doUpload();
}

void CanDataHandler::Impl::doUpload() 
{
    switch (mUploadCxt.state) {
        case NoUpload: {
            // no upload task, try to start new task
            std::string name = fileCtrl_.lock();
            if (name.empty()) {
                // no new task, do nothing
                break;
            }
            mUploadCxt = UploadContext(name, UploadData, Uploading);
            name += ADCM_DATA_FILE_SUFFIX;  // upload data file first

            // do upload
            DataUploader::UploadFileInfo ufInfo = {DataUploader::ADCM_DATA,
                                                   timestampGen(mUploadCxt.name),
                                                   PathTool::join(ADCM_DATA_ROOT, name), PathTool::join(ADCM_ST_DATA_DIR, name),
                                                   true};
            uploader_.upload(ufInfo);
        } break;
        case Uploading: {
            // has upload task in running, nothing need todo
        } break;
        case UploadFailed: {
            // upload failed, retry
            // check retry count
            ++mUploadCxt.retryCount;
            LOG_EVERY_N(ERROR, 5) << "doUpload: uploadFailed!! name: " << mUploadCxt.name
                                  << ", retryCnt: " << mUploadCxt.retryCount;

            mUploadCxt.state = Uploading;
            // do upload
            std::string suffix = (UploadDesc == mUploadCxt.task) ? ADCM_DATA_DESC_FILE_SUFFIX
                                                                  : ADCM_DATA_FILE_SUFFIX;
            std::string name = mUploadCxt.name + suffix;
            DataUploader::UploadFileInfo ufInfo = {DataUploader::ADCM_DATA,
                                                   timestampGen(mUploadCxt.name),
                                                   PathTool::join(ADCM_DATA_ROOT, name), PathTool::join(ADCM_ST_DATA_DIR, name),
                                                   true};
            mWorkThread.looper().postDelayTask(std::bind(&DataUploader::upload, &uploader_, ufInfo),
                                               DATA_UPLOAD_RETRY_INTERVAL_MS);
        } break;
        case UploadDone: {
            if (UploadDesc == mUploadCxt.task) {
                // desc file upload done, current task complete

                // releae resource
                fileCtrl_.unlock(mUploadCxt.name);
                mUploadCxt = UploadContext();

                // recall doUpload to start new task
                mWorkThread.looper().postTask(std::bind(&CanDataHandler::Impl::doUpload, this));
                break;
            }

            // UploadData == mUploadCxt.task
            // data file upload done, upload desc file next
            mUploadCxt.task = UploadDesc;
            mUploadCxt.state = Uploading;

            // do upload
            std::string name = mUploadCxt.name + ADCM_DATA_DESC_FILE_SUFFIX;
            DataUploader::UploadFileInfo ufInfo = {DataUploader::ADCM_DATA,
                                                   timestampGen(mUploadCxt.name),
                                                   PathTool::join(ADCM_DATA_ROOT, name), PathTool::join(ADCM_ST_DATA_DIR, name),
                                                   true};
            uploader_.upload(ufInfo);
        } break;
        default: {
            // This section should not reached
            LOG(ERROR) << "doUpload: unkown state: " << mUploadCxt.state;
        } break;
    }
}

// IF for DataUploader::DataUploaderCallbackIF
void CanDataHandler::Impl::onInited(DataUploader::ErrorCode errorCode) {
    mWorkThread.looper().postTask(
        std::bind(&CanDataHandler::Impl::onUploaderInited, this, (DataUploader::DuOK == errorCode)));
}

void CanDataHandler::Impl::onFetchLogRule(uint64_t timestamp, const std::string& jsonFule) 
{ }

// to save files
void CanDataHandler::Impl::onDump(const DumpInfo& info) 
{
    fileCtrl_.dump(info);
}

void CanDataHandler::Impl::onConfirm(const DumpHeader& header) 
{
    fileCtrl_.confirm(header);
}

///////////////////////////////////

CanDataHandler::CanDataHandler(DataManager& dm, RecoderHandler& recoder)
    : DataHandler(HADNLERID_ADCM, dm), 
	  pImpl_(std::make_unique<Impl>(*this, recoder)) 
{ }

CanDataHandler::~CanDataHandler() 
{ }

bool CanDataHandler::Init()
{
    pImpl_->mWorkThread.start();

    pImpl_->fileCtrl_.Init();

    // input the real work
    pImpl_->dumper_.RegisterDumperWorkerIF(&pImpl_->dumperWorker_);
    pImpl_->dumper_.start();

    pImpl_->mTriggerMgr.start();

    // TODO: specify yaml file path
    pImpl_->mTriggerMgr.loadYaml();

    auto triggerNotify = [this] (TriggerInfo info) {
        pImpl_->dumper_.onTrigger(info);
    };

    pImpl_->mTriggerMgr.setNotifier(triggerNotify);
    return true;
}

void CanDataHandler::deinit() {
    pImpl_->fileCtrl_.deinit();

    // TODO: pImpl_->mTriggerMgr ??

    pImpl_->dumper_.stop();
    pImpl_->mTriggerMgr.stop();

    pImpl_->mWorkThread.stop();
    pImpl_->mWorkThread.join();
}

void CanDataHandler::activate() {
    pImpl_->mWorkThread.looper().postTask(std::bind(&CanDataHandler::Impl::activate, pImpl_));
}

void CanDataHandler::deactivate() {
    pImpl_->mWorkThread.looper().postTask(std::bind(&CanDataHandler::Impl::deactivate, pImpl_));
}

void CanDataHandler::onSn(const std::string& sn) {
    pImpl_->mWorkThread.looper().postTask(std::bind(&CanDataHandler::Impl::onSn, pImpl_, sn));
}

void CanDataHandler::onPowerSwitch(bool isDown) {
    pImpl_->mWorkThread.looper().postTask(std::bind(&CanDataHandler::Impl::onPowerSwitch, pImpl_, isDown));
}

void CanDataHandler::SendData(DataInfo info, uint8_t* data, size_t len) 
{
    // if (info.dtype != DataType::Structured && info.dtype != DataType::Unstructured) {
      //  LOG_EVERY_N(ERROR, 1000) << "sendData: unsupported data type: " << info.dtype
        //                         << ", moduleId: " << info.mid;
        // return;
    // }

    pImpl_->HandleData(info, data, len);

   // if (pImpl_->mRecoder.isActivated()) {
     //   pImpl_->mRecoder.sendData(info, data, len);
   // }
}

void CanDataHandler::onWritten(DumpId id, uint8_t* buffer) {
    // TODO: Dumper.release(id, buffer);
    pImpl_->dumper_.releaseBuffer(id, buffer);
}

// will upload once new file is saved
void CanDataHandler::onWritterConfirmed(DumpId id) 
{
    pImpl_->doUpload();
}


void CanDataHandler::onDump(const DumpInfo& info) {
    pImpl_->onDump(info);
}

void CanDataHandler::onDumperConfirmed(const DumpHeader& header) {
    pImpl_->onConfirm(header);
}

}  // namespace datamanager
}  // namespace hht
