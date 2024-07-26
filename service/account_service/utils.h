/*
 * @author 008584
 * @for account_service
 * @version 1.0
 * @date 2023-11-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef UTILS_H
#define UTILS_H

#include <curl/curl.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <codecvt>
#include <locale>
#include <sqlite_operator.h>

std::string DownloadAndEncodeImage(const std::string& url);
std::string Base64Decode(const std::string& encoded_string);

// Base64 encoding table
const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

#endif /* UTILS_H */