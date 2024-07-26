/*
 * @author 008196
 * @for Can Data Provide
 * @version 0.1
 * @date 2023-05
 * 
 * @Copyrigh (c) HIPHI Co., LTD 2023
 * 
 */

#include "DataManager.h"

#include "ConfigCtrl.h"
#include "RecoderHandler.h"
#include "AdcmHandler.h"
#include "DsvProvider.h"
#include "NohProvider.h"
#include "CamProvider.h"
#include "CanProvider.h"

#include <vector>

#include "HhtLooperThread.h"
#include "HhtTaskLooper.h"
#include "HhtMutex.h"

namespace hht {
namespace datamanager {
static constexpr const char * const DM_CFG_PATH = "/hht_svp/DataManager-runtime/etc/DmConfig.json";

static constexpr size_t MODULE_MAX_RETRY_COUNT = 3;
class DataManager::Impl {
public:
    struct ModuleContext {
        DMBaseModule* module;
        bool isActivated;
        bool isSwitching;
        ErrorCode ecode;
        bool used;
        bool online;
        size_t retryCount;

        ModuleContext(DMBaseModule* _module = nullptr, bool _used = false, bool _online = false)
            : module(_module)
            , isActivated(false)
            , isSwitching(false)
            , ecode(ErrorCode::OK)
            , used(_used)
            , online(_online)
            , retryCount(0) {}
    };

public:
    Impl(DataManager& owner);
    ~Impl();

    void init();
    void activate();
    void deactivate();
    void deinit();

    void waitTransferred();

    void onModuleAcivated(ModuleId id, bool isActivated, ErrorCode ecode);
    void onModuleOnlineChanged(ModuleId id, bool isOnline);

private:
    void handleState();

    inline ConfigCtrl& cfg() { return mOwner.mConfig; }
    inline bool isHandler(ModuleId id) const {
        return HADNLERID_ADCM == id || HADNLERID_RECD == id;
    }
    inline bool isProvider(ModuleId id) const {
        return PROVIDERID_DSV == id || PROVIDERID_NOH == id || PROVIDERID_CAM == id;
    }

public:
    DataManager& mOwner;
    LooperThread mWorkThread;
    Mutex mMutex;
    Condition mCond;

    State mState;
    State mPreState;
    bool mTransfering;
    bool mIsActivated;

    RecoderHandler mRecoderHandler;
    AdcmHandler mAdcmHandler;
    DsvProvider mDsvProvider;
    NohProvider mNohProvider;
    CamProvider mCamProvider;
	CanProvider CanProvider_;

    std::vector<ModuleContext> mContexts;
};

DataManager::Impl::Impl(DataManager& owner)
    : mOwner(owner)
    , mWorkThread()
    , mMutex()
    , mCond()
    , mState(State::Uninit)
    , mPreState(State::InvalidState)
    , mTransfering(false)
    , mIsActivated(false)
    , mRecoderHandler(owner)  // TODO: create module here
    , mAdcmHandler(owner, mRecoderHandler)
    , mDsvProvider(owner, mAdcmHandler)
    , mNohProvider(owner, mAdcmHandler)
    , mCamProvider(owner, mAdcmHandler)
    , CanProvider_(owner, mAdcmHandler)
    , mContexts() {

}

DataManager::Impl::~Impl() {

}

void DataManager::Impl::init() {
    LOG(INFO) << "DataManager::Impl::init.";
    if (mContexts.size()) {
        LOG(ERROR) << "init: already inited";
        return;
    }

    // load cfg
    // TODO: cfg file path
    // TODO: check returen value
    cfg().load(DM_CFG_PATH);

    // start work thread
    mWorkThread.start();

    // fill contexts
    mContexts.resize(MODULE_COUNT);
    mContexts[PROVIDERID_DSV] = {&mDsvProvider,    cfg().useStructrued(),   true};
    mContexts[PROVIDERID_NOH] = {&mNohProvider,    cfg().useStructrued() && cfg().useNoh(), true};
    mContexts[PROVIDERID_CAM] = {&mCamProvider,    cfg().useUnstructrued(), true};
    mContexts[HADNLERID_ADCM] = {&mAdcmHandler,    cfg().useUpload(),       true};
    mContexts[HADNLERID_RECD] = {&mRecoderHandler, cfg().useRecord(),       false};

    // Check: all modules has been created
    for (auto& cxt: mContexts) {
        assert(cxt.module);
    }

    // init members
    for (auto it = mContexts.rbegin(); it != mContexts.rend(); ++it) {
        if(PROVIDERID_CAM == it->module->id() && !cfg().useUnstructrued() && !cfg().initUnstructured()) {
            // special for HIL test.
            LOG(ERROR) << "init: cfg() set camera need not init.";
            continue;
        }
        // init all members, whether used or not.
        bool ret = it->module->init();
        if (!ret) {
            LOG(ERROR) << "init: init module failed. mid: " << it->module->id();
            it->used = false;
        }
    }
}

void DataManager::Impl::activate() {
    LOG(INFO) << "DataManager::Impl::activate.";
    if (mIsActivated) {
        // already activated
        return;
    }
    mIsActivated = true;
    mTransfering = true;

    // activate modules
    for (auto it = mContexts.rbegin(); it != mContexts.rend(); ++it) {
        if (!it->used || !it->online) {
            continue;
        }

        if (!it->isSwitching && !it->isActivated) {
            LOG(INFO) << "activate: activate module: " << it->module->id();
            it->isSwitching = true;
            it->module->activate();
        }
    }
    LOG(INFO) << "DataManager::Impl::activate. EEE";
}

void DataManager::Impl::deactivate() {
    LOG(INFO) << "DataManager::Impl::deactivate.";
    if (!mIsActivated) {
        // has not activated
        return;
    }
    mIsActivated = false;
    mTransfering = true;

    for (auto it = mContexts.begin(); it != mContexts.end(); ++it) {
        it->isSwitching = true;
    }

    // deactivate modules
    for (auto it = mContexts.begin(); it != mContexts.end(); ++it) {
        if (!it->used || !it->online) {
            continue;
        }
        if (!it->isSwitching && it->isActivated) {
            LOG(INFO) << "deactivate: deactivate module: " << it->module->id();
            it->isSwitching = true;
            it->module->deactivate();
        }
    }
}

void DataManager::Impl::deinit() {
    LOG(INFO) << "DataManager::Impl::deinit.";
    // edinit all modules, no matter used or not.
    for (auto it = mContexts.begin(); it != mContexts.end(); ++it) {
        it->module->deinit();
    }

    mWorkThread.stop();
    mWorkThread.join();
}

void DataManager::Impl::waitTransferred() {
    AutoLock al(mMutex);
    while (mTransfering) {
        mCond.wait(mMutex);
    }
}

/////////////////////////////////////
void DataManager::Impl::onModuleAcivated(ModuleId id, bool isActivated, ErrorCode ecode) {
    LOG(INFO) << "onModuleAcivated: id: " << id << ", activated: " << isActivated
              << ", ecode: " << ecode;
    if (id >= mContexts.size()) {
        LOG(ERROR) << "onModuleAcivated: invalid moduleId. id: " << id
                   << ", activated: " << isActivated << ", ecode: " << ecode;
        return;
    }

    ModuleContext& cxt = mContexts[id];
    if (ErrorCode::OK != cxt.ecode) {
        LOG(ERROR) << "onMemStateChanged: changed failed. id: " << id
                   << ", activated: " << isActivated << ", ecode: " << ecode;
    }

    cxt.ecode = ecode;
    cxt.isActivated = isActivated;
    cxt.isSwitching = false;
    handleState();
}

void DataManager::Impl::onModuleOnlineChanged(ModuleId id, bool isOnline) {
    // LOG(INFO) << "onModuleOnlineChanged: mid: " << id << "ol: " << isOnline;
    if (id >= mContexts.size()) {
        LOG(ERROR) << "onModuleOnlineChanged: invalid moduleId. id: " << id
                   << ", online: " << isOnline;
        return;
    }
     mContexts[id].online = isOnline;

    handleState();
}

void DataManager::Impl::handleState() {
    bool handlerOffline = (!mContexts[HADNLERID_RECD].used || !mContexts[HADNLERID_RECD].online) &&
                          (!mContexts[HADNLERID_ADCM].used || !mContexts[HADNLERID_ADCM].online);
    bool switch2Act = !handlerOffline && mIsActivated;
    bool transfering = true;
    for (auto& cxt: mContexts) {
        // LOG(INFO) << "++ id:" << cxt.module->id() << " act:" << cxt.isActivated
        //           << " sw:" << cxt.isSwitching << " eo:" << cxt.ecode << " us:" << cxt.used
        //           << " ol:" << cxt.online << " rc:" << cxt.retryCount << " s2a:" << switch2Act;
        do {
            if (!cxt.used || cxt.isSwitching) {
                // skip unused and switching modules
                break;
            }

            if (cxt.ecode != ErrorCode::OK) {
                // handle module error
                if (cxt.retryCount >= MODULE_MAX_RETRY_COUNT) {
                    // reach max retry count, unused this module
                    cxt.used = false;
                    break;
                }

                ++cxt.retryCount;
                cxt.isSwitching = true;
                cxt.module->deactivate();  // TODO: postDelayTask?
                break;
            }

            // ErrorCode::OK == cxt.ecode
            cxt.retryCount = 0;
            if (switch2Act == cxt.isActivated) {
                // if module state is equal to module target state, skip.
                break;
            }

            // cxt.isActivated != mIsActivated
            cxt.isSwitching = true;
            if (switch2Act) {
                LOG(INFO) << "handleState: activate module: " << cxt.module->id();
                cxt.module->activate();
            } else {
                LOG(INFO) << "handleState: deactivate module: " << cxt.module->id();
                cxt.module->deactivate();
            }
        } while (false);
        if (cxt.used && cxt.isSwitching) {
            transfering = true;
        }
    }
    if (mTransfering != transfering) {
        AutoLock al(mMutex);
        mTransfering = transfering;
        if (!mTransfering) {
            mCond.signal();
        }
    }
}

////////////////////////////////////

DataManager::DataManager() : pImpl_(std::make_unique<Impl>(*this)) { }
DataManager::~DataManager() { }

void DataManager::onlineChanged(ModuleId id, bool isOnline) {
    pImpl_->mWorkThread.looper().postTask(
        std::bind(&DataManager::Impl::onModuleOnlineChanged, pImpl_, id, isOnline));
}

void DataManager::start() {
    pImpl_->init();
    pImpl_->mWorkThread.looper().postTask(
        std::bind(&DataManager::Impl::activate, pImpl_));
}

void DataManager::stop() {
    pImpl_->mWorkThread.looper().postTask(
        std::bind(&DataManager::Impl::deactivate, pImpl_));
    while (pImpl_->mIsActivated || pImpl_->mTransfering) {
        pImpl_->waitTransferred();
    }
    pImpl_->deinit();
}

void DataManager::onAcivated(ModuleId id, bool isActivated, ErrorCode ecode) {
    pImpl_->mWorkThread.looper().postTask(
        std::bind(&DataManager::Impl::onModuleAcivated, pImpl_, id, isActivated, ecode));
}

void DataManager::onSn(const std::string& sn) {
    LOG(INFO) << "onSn: " << sn.size() << ", " << sn << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    pImpl_->mWorkThread.looper().postTask(
        std::bind(&AdcmHandler::onSn, pImpl_->mAdcmHandler, sn));
}

void DataManager::onPowerSwitch(bool isDown) {
    LOG(INFO) << "onPowerSwitch: " << isDown;
    pImpl_->mWorkThread.looper().postTask(
        std::bind(&AdcmHandler::onPowerSwitch, pImpl_->mAdcmHandler, isDown));
}

}  // namespace datamanager
}  // namespace hht
