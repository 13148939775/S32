/*
 * @author 007313 008196
 * @file dump to storage interface
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DATA_DUMPER_WORKER_IF_H
#define DATA_DUMPER_WORKER_IF_H

namespace HHT {
namespace DataManager {

class DumperWorkerIF {
public:
    virtual void OnRequestDump(const DumpInfo info) = 0;
    virtual void OnRequestConfirm(const DumpHeader header) = 0;
};

}
}

#endif /* DATA_DUMPER_WORKER_H */
