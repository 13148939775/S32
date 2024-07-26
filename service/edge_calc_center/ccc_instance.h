#ifndef CCC_INSTANCE_H
#define CCC_INSTANCE_H

#include <node_log.h>

namespace HHT {

class CCC {
public:
    explicit CCC(const std::string& name, std::string path = "", bool isService = false)
    {
        std::cout << "app " << name << " is constructed" << std::endl;
    }

    ~CCC()
    { }

    bool DoInit()  
    { }
    bool DoSuspend() 
    { }
    bool DoResume() 
    { }
};
}

#endif

