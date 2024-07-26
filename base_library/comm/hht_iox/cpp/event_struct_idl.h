/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EVENT_STRUCT_IDL_H
#define EVENT_STRUCT_IDL_H

#include <cstdint>

namespace HHT {
//! [request]
struct AddRequest
{
    uint64_t augend{0};
    uint64_t addend{0};
};
//! [request]

//! [response]
struct AddResponse
{
    uint64_t sum{0};
};
}
#endif /* EVENT_STRUCT_IDL_H */

