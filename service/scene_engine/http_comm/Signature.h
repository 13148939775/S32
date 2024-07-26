#ifndef SIGNATURE_H
#define SIGNATURE_H
#include <openssl/hmac.h>
#include <string>
#include "Encode.h"
#include <iomanip> //使用C++标准库中的urlencode函数实现RFC 3986规则编码

class Signature
{
public:
    static Signature& GetInstance()
    {
        static Signature sig;
        return sig;
    }
public:
    std::string GetSignature(const std::string &stringToSign, const std::string &signKey)
    {

        unsigned char *mac = NULL;
        unsigned int mac_length = 0;
        mac = (unsigned char *)malloc(64);
        Encode encode;
        encode.HmacEncode("sha256", signKey.c_str(), signKey.length(), stringToSign.c_str(),
                        stringToSign.length(), mac, mac_length);
        std::string signBase64 = encode.base64_encode(mac, mac_length);
        free(mac);
        return signBase64;
    }
    std::string GetUrlEncode(const std::string &cqsString){
        Encode encode;
        return encode.UrlEncode(cqsString);
    }
};


#endif