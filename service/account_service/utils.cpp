/*
 * @author 008584
 * @for account_service
 * @version 1.0
 * @date 2023-11-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "utils.h"

using namespace HHT;

struct write_data {
    std::ostream* os;
};

size_t Writer(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    struct write_data* wd = static_cast<write_data*>(userdata);
    size_t totalSize = size * nmemb;
    wd->os->write(ptr, totalSize);
    return totalSize;
}

std::string Base64Encode(char const* bytes_to_encode, unsigned int in_len)
{
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for(i = 0; (i <4) ; i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if(i)
    {
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

        for(j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while((i++ < 3))
            ret += '=';

    }

    return ret;

}

std::string DownloadAndEncodeImage(const std::string& url)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        std::ostringstream os;
        struct write_data { std::ostream* os; } wd;
        wd.os = &os;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &wd);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            throw std::runtime_error("Failed to download image");

        /* always cleanup */
        curl_easy_cleanup(curl);

        return Base64Encode(os.str().c_str(), os.str().size());
    }

    curl_global_cleanup();

    throw std::runtime_error("Failed to create cURL handle");
}

//图片解码
bool IsBase64(unsigned char c)
{
    return std::strchr(base64_chars.data(), c) != nullptr;
}

std::string Base64Decode(const std::string& encoded_string)
{
    size_t in_len = encoded_string.size();
    size_t i = 0;
    size_t j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && ( encoded_string[in_] != '=') && IsBase64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) {
            for(i = 0; i <4; i++)
                char_array_4[i] = static_cast<unsigned char>(base64_chars.find(char_array_4[i]));

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30)>>4);
            char_array_3[1] = ((char_array_4[1] & 0xf)<<4) + ((char_array_4[2] & 0x3c)>>2);
            char_array_3[2] = ((char_array_4[2] & 0x3)<<6) + char_array_4[3];

            for(i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if(i)
    {
        for(j = i; j <4; j++) char_array_4[j] = 0;

        for(j = 0; j <4; j++)
            char_array_4[j] = static_cast<unsigned char>(base64_chars.find(char_array_4[j]));

        char_array_3[0] = ( char_array_4[0] <<2 ) + ((char_array_4[1] &0x30)>>4 );
        char_array_3[1] = ((char_array_4[1] &0xF)<<4 ) + ((char_array_4[2]&0x3C)>>2 );
        char_array_3[2] = ((char_array_4[2] &0x3)<<6 ) + char_array_4[3];

        for(j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}