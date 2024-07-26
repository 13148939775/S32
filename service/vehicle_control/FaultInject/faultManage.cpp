
#include "faultManage.h"

void FaultManage::AddTopic(std::shared_ptr<FaultSimu>& fs)
{
    faultSimuVec_.push_back(fs);
}

void FaultManage::SetFaultSimu(std::string& topic)
{

}

void FaultManage::CancelFaultSimu(std::string& topic)
{

}