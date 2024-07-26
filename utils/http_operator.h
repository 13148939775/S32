/*
 * @author 008584
 * @for dds_operator
 * @version 1.0
 * @date 2023.11.22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <curl/curl.h>

class HttpOperator {
public:
    static std::string SendGetRequest(const std::string& url)
    {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();

        return readBuffer;
    }

    static std::string SendPostRequest(const std::string& url, const std::string& data)
    {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
            curl_easy_cleanup(curl);
        }

        return readBuffer;
    }
private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp)
    {
        userp->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
};