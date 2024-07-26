#ifndef ENCODE_H
#define ENCODE_H

#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <string>

class Encode {
public:
    static Encode& GetInstance()
    {
        static Encode ec;
        return ec;
    }

    std::string base64_encode(unsigned char const *bytes_to_encode, unsigned int in_len)
    {
        std::string ret;
        int i = 0;
        unsigned char char_array_3[3];
        unsigned char char_array_4[4];
        while (in_len--)
        {
            char_array_3[i++] = *(bytes_to_encode++);
            if (i == 3)
            {
                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (i = 0; (i < 4); i++)
                    ret += base64_chars[char_array_4[i]];
                i = 0;
            }
        }
        if (i != 0)
        {
            int j = 0;
            for (j = i; j < 3; j++)
                char_array_3[j] = '\0';

            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (j = 0; (j < i + 1); j++)
                ret += base64_chars[char_array_4[j]];

            while ((i++ < 3))
                ret += '=';
        }
        return ret;
    }

    std::string UrlEncode(const std::string &s)
    {
        [[maybe_unused]] static const char *const hex = "0123456789ABCDEFABCDEF";
        std::ostringstream escaped;
        escaped.fill('0');
        escaped << std::hex;

        for (auto C : s)
        {
            if (std::isalnum(static_cast<unsigned char>(C)) || C == '-' || C == '_' || C == '.' || C == '~')
            {
                escaped << C;
            }
            else
            {
                escaped << '%' << std::setw(2) << std::uppercase << static_cast<int>(static_cast<unsigned char>(C));
            }
        }

        return escaped.str();
    }

    std::string Sha256(const std::string &str)
    {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str.data(), str.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        {
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
        }

        return ss.str();
    }

    int HmacEncode(const char *algo, const char *key, unsigned int /*key_length*/,
                        const char *input, unsigned int /*input_length*/, unsigned char *&output,
                        unsigned int &output_length)
    {
        const EVP_MD *engine = NULL;
        if (std::string(algo).compare("sha256") == 0)
        {
            engine = EVP_sha256();
        }
        HMAC_CTX *ctx = HMAC_CTX_new();
        std::string str1(key);
        HMAC_Init_ex(ctx, key, str1.length(), engine, NULL);
        std::string str2(input);
        HMAC_Update(ctx, (unsigned char *)input, str2.length());
        HMAC_Final(ctx, output, &output_length);
        HMAC_CTX_free(ctx);

        return 0;
    }
private:
    const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
};
#endif