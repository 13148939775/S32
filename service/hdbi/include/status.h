/**
 * @file status.h
 * @brief 
 * @author T001294
 * @version 1.0
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023  HRYT
 * 
 */

#ifndef COMMON_STATUS_H_
#define COMMON_STATUS_H_

#include <string>

namespace common {
class Status {
public:
    Status() :
        code_(true), msg_("no value input") {
    }
    virtual ~Status() = default;

    Status(const std::string &msg) :
        code_(false), msg_(msg) {
    }
    bool ok() const {
        return code_;
    }

    bool operator==(const Status &rhs) const {
        return (this->code_ == rhs.code_) && (this->msg_ == rhs.msg_);
    }
    bool operator!=(const Status &rhs) const {
        return !(*this == rhs);
    }
    const std::string &error_message() const {
        return this->msg_;
    }
    std::string ToString() const {
        if (ok()) {
            return "OK";
        }
        return this->msg_;
    }

private:
    bool code_;
    std::string msg_;
};

#define RETURN_STATUS_OK() \
    return common::Status();

#define RETURN_STATUS(ST)                     \
    if (!ST.ok()) {                           \
        return common::Status(ST.ToString()); \
    }

} // namespace common

#endif //COMMON_STATUS_H_