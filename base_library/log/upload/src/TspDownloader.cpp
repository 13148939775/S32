/*
 * @author 001293
 * @Requesting log upload rules interface.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "TspDownloader.h"
#include <sys/time.h>
#include <sstream>
#include <nlohmann/json.hpp>
#include <node_log.h>
#include "upload.h"

std::string TspDownloader::DownloadCfgFromTSP()
{
    std::string response;
    Request request;
    std::stringstream ss;
    std::string str;
    ss << Upload::GetLogrtHost() << Upload::GetLogrtServiceName() << Upload::GetLogrtDownloadUploadRule() << "?";
    str = ss.str();
    request.url = str + "vin=" + Upload::GetVin() + "&sn=" + Upload::GetSn();
    ss.str("");
    HHT_LOG(INFO) << "request.url: " << request.url;

    request.header.accessKeyId = Upload::GetSn();
    HHT_LOG(INFO) << "accessKeyId: " << request.header.accessKeyId;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    ss << ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
    request.header.timestamp = ss.str();
    ss.str("");
    HHT_LOG(INFO) << "timestamp: " << request.header.timestamp;
    ss << Upload::GetLogrtServiceName() << Upload::GetLogrtDownloadUploadRule();
    str = ss.str();
    std::string stringToSign = str + "&accessKeyId=" + Upload::GetSn() + "&timestamp=" + request.header.timestamp + "&sn=" + Upload::GetSn() + "&vin=" + Upload::GetVin();
    HHT_LOG(INFO) << "stringToSign:" << stringToSign;
    TspProxy tspProxy;
    request.header.signature = tspProxy.GetSignature(stringToSign, Upload::GetVin());
    HHT_LOG(INFO) << request.header.signature;
    ss << "vin=" << Upload::GetVin() << "&sn=" << Upload::GetSn() << std::endl;
    request.data = ss.str();
    ss.str("");
    HHT_LOG(INFO) << "request.data: " << request.data;
    LogHttpClient logHttpClient;
    auto ret = logHttpClient.HttpGet(request, response);
    HHT_LOG(INFO) << "HttpGet:" << response << ret;
    return response;
}

//解析get请求返回的json串得到obsconfig的值，同时根据返回值可以判断get请求的内容是否正确
bool TspDownloader::ParseObsCfg(std::string response){
    nlohmann::json obsCfg;
    if (response.empty() == true|| (((obsCfg = nlohmann::json::parse(response)).contains("code")) == true && obsCfg["code"] != "000000")) {
        HHT_LOG(INFO)<< "LogUpload::getUploadConfFromTPS response is failed, response is " << response;
        return false;
    }

    ObsUploader::SetObsconfig(obsCfg);
    ObsUploader obs;
    obs.PrintObsconfig();

    return true;
}

bool TspDownloader::GetUploadConfFromTSP()
{
    // std::string response;
    Request request;
    std::stringstream ss;
    std::string str;
    ss << Upload::GetLogrtHost() << Upload::GetLogrtServiceName() << Upload::GetLogrtGetObsPath() << "?";
    str = ss.str();
    request.url = str + "vin=" + Upload::GetVin() + "&sn=" + Upload::GetSn();
    ss.str("");
    HHT_LOG(INFO) << request.url;
    request.header.accessKeyId = Upload::GetSn();
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ss << ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
    request.header.timestamp = ss.str();
    HHT_LOG(INFO) << request.header.timestamp;
    ss.str("");
    ss << Upload::GetLogrtServiceName() << Upload::GetLogrtGetObsPath();
    str = ss.str();
    std::string stringToSign = str + "&accessKeyId=" + Upload::GetSn() + "&timestamp=" + request.header.timestamp + "&sn=" + Upload::GetSn() + "&vin=" + Upload::GetVin();
    TspProxy tspProxy;
    request.header.signature = tspProxy.GetSignature(stringToSign, Upload::GetVin());
    HHT_LOG(INFO) << "signature: " << request.header.signature;
    ss << "vin=" << Upload::GetVin() << "&sn=" << Upload::GetSn() << std::endl;
    request.data = ss.str();
    ss.str("");
    LogHttpClient logHttpClient;
    [[maybe_unused]] auto ret = logHttpClient.HttpGet(request, uploadConfResponse_);
    HHT_LOG(INFO) << "httpget:" << uploadConfResponse_;

    bool res = ParseObsCfg(uploadConfResponse_);
    return res;
}

std::string TspDownloader::GetUploadConfResponse() {
    return uploadConfResponse_;
}