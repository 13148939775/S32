#ifndef FAULT_SIMU_H
#define FAULT_SIMU_H

#include <string>

#include "nlohmann/json.hpp"
#include "TopicData_Center.h"

class FaultSimu : public TopticDataCenter::Observer{
public:
    FaultSimu(const std::string& faulttype, const std::string& faultname);

    virtual ~FaultSimu() { }

    void RegistryFaultSim(std::string&  fault);
    void RemoveFaultSimu(std::string&  fault);

    void ManageConflict(const std::string& fault);
    void transimission(const std::string& fault);

    void OnNotify(TopticDataCenter& siginfo);

    static void CreateDDSThread();

public:
    std::string fault_type_;
    std::string fault_name_;

};
#endif