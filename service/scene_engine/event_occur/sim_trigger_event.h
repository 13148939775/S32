
/*
 * @author 008196
 * @for custom scene manager read/conflict
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SIM_TRIGGER_EVENT_H
#define SIM_TRIGGER_EVENT_H

#include <queue>
#include <string>

#include <utils/dbc/data_block_center.h>
#include <utils/dbc/data_block.h>



class SimTriggerEventTable {
public:
    void PublishEvent(std::string& event)
    {
        auto blk = std::make_shared<DataBlockImpl<LightState>>(event);
        auto& store = blk->Write();
        store.status = true;
        DataBlockCenter::GetInstance().Push(blk);
    }

    void CancelEvent(std::string event)
    {           
       //auto blk = std::make_shared<DataBlockImpl<LightState>>(event, pos);
       //auto& store = blk->Write();
       //store.status = false;
       //DataBlockCenter::GetInstance().Pop(blk);
    }
};

#endif