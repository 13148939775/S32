/*
 * @author 001293
 * @Signature interface.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TSP_PROXY_H
#define TSP_PROXY_H

#include <string>

class TspProxy{
public:
    std::string GetSignature(const std::string& stringToSign, const std::string& signKey);
};

#endif