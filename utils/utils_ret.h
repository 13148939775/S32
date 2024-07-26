/*
 * @author 008196
 * @for application log file entry
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UTILS_H
#define UTILS_H

namespace Hdf_platform {
using utils_ret_t = int;

enum class RetCode {
    RET_OK,
    RET_WARN,
    RET_ERROR,
    RET_INVALID_ARGUMENT,
    RET_NOT_INITIALIZED,
    RET_NOT_FOUND,
    Exist,
    NotExist,
};

}

#endif /* UTILS_H */
