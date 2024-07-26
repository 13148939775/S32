/*
 * @author 001293
 * @Signature interface.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "TspProxy.h"
#include "upload.h"
#include "base64.h"

std::string TspProxy::GetSignature(const std::string& stringToSign, const std::string& signKey) 
{
    unsigned char *mac = NULL;
    unsigned int mac_length = 0;
    mac = (unsigned char *)malloc(64);
    BaseMac bm;
    bm.HmacEncode("sha256", signKey.c_str(), signKey.length(), stringToSign.c_str(),
        stringToSign.length(), mac, mac_length);
    std::string signBase64 = bm.base64_encode(mac, mac_length);
    free(mac);
    return signBase64;
}