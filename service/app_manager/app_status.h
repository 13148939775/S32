/*
 * @author 008196
 * @for custom scene scheduler
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef APP_STATUS
#define APP_STATUS

namespace HHT {
enum class AppStatus : uint8_t {
    UnInitialized = 0,
    Initialized,
    Started,
    Paused,
    Stopped,
    Normal_Stopped,
    Uninterruptible,
    Error
};

}
#endif /* DCFF490A_E90C_403E_A44C_8F0A7CB3D19D */
