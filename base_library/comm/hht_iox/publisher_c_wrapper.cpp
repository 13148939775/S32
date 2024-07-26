/*
 * @author 008196
 * @for publisher kit c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "publisher_c_wrapper.h"
#include "cpp/publisher_kit.h"

#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"

//namespace HHT {
extern "C" {

//HHT::Publisher* pbTmp;
    void  newPubClass() {
        //pbTmp  = new HHT::Publisher("new test", HHT::PROTOCOL_ICEORYX_DDS);
    }
    //HHT::Publisher pbTmp;
    int PubClass_Pub(int evtID) {
        std::unique_ptr<HHT::Publisher> pb_(new HHT::Publisher("test", HHT::PROTOCOL_ICEORYX_DDS));
        //HHT::Publisher* pbTmp =  new HHT::Publisher("new test", HHT::PROTOCOL_ICEORYX_DDS);
        // HHT::Publisher& pbTmp = HHT::Publisher::GetInstance(); //.Pub(evtID);
        pb_->Pub(evtID);

        return 1;
    }

    void deletePubClass() {
       //delete pbTmp;
    }
}
//}