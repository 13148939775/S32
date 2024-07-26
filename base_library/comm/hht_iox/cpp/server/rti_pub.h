/*
 * @author 008196
 * @for application log file entry
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef RTI_PUB_H
#define RTI_PUB_H

#include <string>
#include "base_pub_interface.h"
#include "comm_config.h"

namespace HHT {

class RtiPub : public BasePubInterface {
public:
    RtiPub(std::string& owner)
      : owner_(owner) { }

    ~RtiPub() = default;

    bool Init() override
    {

    }

    int Pub(int EvtID) override
    {
        
    }
private:
    std::string  owner_;
};

}

#endif