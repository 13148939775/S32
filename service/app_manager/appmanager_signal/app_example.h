 /* @author T001285
 * @for application
 * @version 0.1
 * @date 2023-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef AppExample_H_
#define AppExample_H_

#include "hdbm_app_if.h"
#include <string>
#include "hdbm_app_reg.h"

namespace HHT {
/*!
 * \brief           Main class representing the application
 */
class AppExample :public HDBMAppIF /*,HDBMAppReg<AppExample>*/  {
public:
    AppExample()/*: HDBMAppReg(this, name, path, isService){}*/{};
    ~AppExample(){};
    AppExample(const AppExample&) = delete;
    AppExample(const AppExample&&) = delete;
    AppExample operator=(const AppExample&) = delete;
    AppExample operator=(const AppExample&&) = delete;

    bool DoInit() override;
    bool DoSuspend() override;  // to release the IO resource
    void Run() override;
    bool DoShutdown() override;  // to release its resource include IO
};
}  // namespace application
#endif  
