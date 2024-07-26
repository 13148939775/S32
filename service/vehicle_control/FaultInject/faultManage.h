#ifndef FAULT_MANAGE_H
#define FAULT_MANAGE_H

#include <vector>
#include <string>

#include "faultSimu.h"

class FaultManage {
public:
    static FaultManage& GetInstance()
    {
        static FaultManage fm;
        return fm;
    }

public:
    void AddTopic(std::shared_ptr<FaultSimu>& fs);

    void SetFaultSimu(std::string& topic);
    void CancelFaultSimu(std::string& topic);
private:
    std::vector<std::shared_ptr<FaultSimu>> faultSimuVec_;

};

#endif