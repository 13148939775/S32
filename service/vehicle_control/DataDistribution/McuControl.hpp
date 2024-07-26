/*
 * @author 008555
 * @for application vechicleControl to MCU
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <memory>

#include "McuImplementation.h"
#include "McuInterface.h"

class MCUController {
public:
    static MCUController& GetInstance() 
    {
        static MCUController instance;
        return instance;
    }

    int SendDataToMCU(const std::vector<int>& data) 
    {
        // 执行额外的逻辑或数据处理
        // ...
    
        // 调用MCU接口发送数据给MCU
        return mcuInterface_->SendToMCU(data);
    }

    void SetMCUInterface(std::unique_ptr<MCUInterface> mcuInterface) 
    {
        mcuInterface_ = std::move(mcuInterface);
    }

private:
    MCUController() : mcuInterface_(nullptr) {}
    MCUController(const MCUController&) = delete;
    MCUController& operator=(const MCUController&) = delete;
    std::unique_ptr<MCUInterface> mcuInterface_;
};