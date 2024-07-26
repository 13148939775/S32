/*
 * @author 001293
 * @Provide functions for encoding and encryption.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BASE64_H
#define BASE64_H

#include <string>
#include "openssl/hmac.h"

class BaseMac {
public:
    //不依赖于类的实例，也不需要访问类的任何成员变量或成员函数，因此将其声明为类的静态函数是比较合适的做法。
    static std::string base64_encode(unsigned char const *bytes_to_encode, unsigned int in_len);
    static int HmacEncode(const char *algo, const char *key, unsigned int /*key_length*/,
                            const char *input, unsigned int /*input_length*/, unsigned char *&output,
                            unsigned int &output_length) ;
};
#endif                        
