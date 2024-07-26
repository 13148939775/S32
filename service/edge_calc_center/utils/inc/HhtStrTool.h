#ifndef HHTSTRTOOL_H
#define HHTSTRTOOL_H

#include <stdarg.h>

#include <string>
#include <list>

namespace hht {
class StrTool {
public:
    static std::string format(const char* fmt, ...) {
        static constexpr size_t BUF_MAX_LEN = 512;
        std::string ret;

        va_list args;
        va_start(args, fmt);

        va_list tmp_args;
        va_copy(tmp_args, args);
        int len = vsnprintf(nullptr, 0, fmt, tmp_args);
        va_end(tmp_args);

        if (len > 0) {
            size_t locLen = (size_t)len;
            char buf[BUF_MAX_LEN] = {'\0'};
            if (locLen > BUF_MAX_LEN - 1) {
                locLen = BUF_MAX_LEN - 1;
            }
            vsnprintf(buf, locLen + 1, fmt, args);
            ret = std::string(buf);
        }

        va_end(args);
        return ret;
    }

    static std::list<std::string> split(const std::string& text,
                                        const std::string& delimiter) {
        std::list<std::string> splited;
        size_t lastIndex = 0;
        while (true) {
            size_t index = text.find(delimiter, lastIndex);
            if (text.npos == index) {
                splited.push_back(text.substr(lastIndex));
                break;
            } else {
                splited.push_back(text.substr(lastIndex, index - lastIndex));
                lastIndex = index + delimiter.size();
            }
        }
        return splited;
    }

    static std::string join(const std::list<std::string> texts,
                            const std::string& delimiter) {
        std::string ret;
        for (auto it = texts.begin(); it != texts.end(); ++it) {
            if (it == texts.begin()) {
                ret += *it;
            } else {
                ret += delimiter + *it;
            }
        }

        return ret;
    }
};

} // namespace hht








#endif // HHTSTRTOOL_H