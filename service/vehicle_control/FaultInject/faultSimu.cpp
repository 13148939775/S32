#include "faultSimu.h"

#include  <unordered_map>

#include "DDSservice.h"
#include "vehicle_door.hpp"
#include "ddsrepliermanage.h"

std::unordered_map<std::string, std::unordered_map<uint8_t, std::string>> faultList = {
    {"DoorFault",
                {
                    {0, "FaultDoorType_InActive"},
                    {1, "FaultDoorType_Expectedworkend"},
                    {2, "FaultDoorType_LatchFault"},
                    {3, "FaultDoorType_DriveTimeOut"},
                    {4, "FaultDoorType_HeatProtest"},
                    {5, "FaultDoorType_PowerStatus"},
                    {6, "FaultDoorType_VehicleNotStationary"},
                    {7, "FaultDoorType_CommandConflict"},
                    {8, "FaultDoorType_StallOccured"},
                    {9, "FaultDoorType_ManualRelease"}
                    
                }
    },
    {"WindowFault",
                {
                    {0, "FaultWinType_WinInvalid"},
                    {1, "FaultWinType_WinCommandConflict"}
                }
    
    },
    {"ChairFault",
                {
                    {0, "FaultChairType_ChairControllInvalid"},
                    {1, "FaultChairType_ChairCommandConflict"}
                }

    },
    {"LightFault",
                {
                    {0, "FaultLightType_LightInvalid"},
                    {1, "FaultLightType_LightCommandConflict"}
                }

    },
    {"RearMirrorFault",
                {
                    {0, "FaultRearMirrorType_MirrorSignalInvalid"},
                    {1, "FaultRearMirrorType_MirrorCommandConflict"}
                }

    }
};

FaultSimu::FaultSimu(const std::string& faulttype, const std::string& faultname)
      : fault_type_(faulttype),
        fault_name_(faultname)
{ 
    DDSReplierManage::GetInstance().CreateDDSReply(fault_name_);
    DDSReplierManage::GetInstance().InitDDSReply(fault_name_);
}

void FaultSimu::CreateDDSThread()
{
    DDSReplierManage& dds_reply = DDSReplierManage::GetInstance();
    std::thread th_([&dds_reply]() {
        dds_reply.CreateLoopRequest();
    });
    th_.detach();
}


void FaultSimu::RegistryFaultSim(std::string&  fault)
{
    TopticDataCenter::GetInstance().AttachObserver(fault, this); 
}
void FaultSimu::RemoveFaultSimu(std::string&  fault)
{
    TopticDataCenter::GetInstance().RemoveObserver(fault, this); 
}

void FaultSimu::ManageConflict(const std::string& fault)
{

}
void FaultSimu::transimission(const std::string& fault)
{
    
}

void FaultSimu::OnNotify(TopticDataCenter& siginfo)
{
    
}