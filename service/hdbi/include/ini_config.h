/**
 * @file ini_config.h
 * @brief 
 * @author T001294
 * @version 1.0
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023  HRYT
 * 
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <sstream>
#include <map>
#include <fstream>

#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace common {
namespace util {
inline vector<string> split(const string &s, const string &seperator) {
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    try {
        while (i != s.size()) {
            // 找到字符串中首个不等于分隔符的字母；
            int flag = 0;
            while (i != s.size() && flag == 0) {
                flag = 1;
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[i] == seperator[x]) {
                        ++i;
                        flag = 0;
                        break;
                    }
            }

            // 找到又一个分隔符，将两个分隔符之间的字符串取出；
            flag = 0;
            string_size j = i;
            while (j != s.size() && flag == 0) {
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[j] == seperator[x]) {
                        flag = 1;
                        break;
                    }
                if (flag == 0)
                    ++j;
            }
            if (i != j) {
                result.emplace_back(s.substr(i, j - i));
                i = j;
            }
        }
    } catch (std::out_of_range &exc) {
        std::cerr << exc.what() << " string:" << s << " seprate:" << seperator << std::endl;
    }

    return result;
}

}
} // namespace common::util

#endif
