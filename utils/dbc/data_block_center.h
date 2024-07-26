
/*
 * @author 008196
 * @for custom scene manager read/conflict
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DATA_BLOCK_CENTER_H
#define DATA_BLOCK_CENTER_H

#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>

#include "data_block.h"

#define DATA_BLK_MAX_ID 128

class DataBlockCenter {

public:
    class Observer {
    public:
        virtual void OnNotify(const DataBlockCenter& dbc) = 0;
    };

    static DataBlockCenter& GetInstance()
    {
        static DataBlockCenter dbc;
        return dbc;
    }

    using ObserverPtr = Observer*;

    bool AttachObserver(std::string& blk, ObserverPtr ob)
    {
        auto res = observers_[blk].insert(ob);
        return res.second;
    }

    bool RemoveObserver(std::string& blk, ObserverPtr ob)
    {
        auto res = observers_[blk].erase(ob);
        return res == 1;
    }

    void Notify(std::string& topic)
    {
        for(const auto& ele : observers_[topic]) {
                ele->OnNotify(*this);
         }
    }

    void Push(std::shared_ptr<DataBlock> blk)  // store one event
    {
        std::string id = blk->GetId();
        uint16_t seq = namePosVer[id];
        blks_[id] = blk;
        blkFlag_.set(seq);
        blkFlagState.set(seq);
        newseq = seq;
        //}
    }

    void Pop(std::shared_ptr<DataBlock> blk)  // pop one event
    {
        std::string id = blk->GetId();
        uint16_t seq = namePosVer[id];
        //if (id < static_cast<uint32_t>(BLK_MAX)) {
        blkFlagState.reset(seq);
        newseq = seq;
        //}
    }

    uint32_t GetFlag() const 
    {
        return newseq;
    }

    bool GetEventState()
    {
        return blkFlagState.test(newseq);
    }
private:
    std::bitset<DATA_BLK_MAX_ID> blkFlag_;
    std::bitset<DATA_BLK_MAX_ID> blkFlagState;
    std::unordered_map<std::string, std::unordered_set<ObserverPtr>> observers_;  // permit an observer to register different event
    std::unordered_map<std::string, std::shared_ptr<DataBlock>> blks_;
    const std::vector<std::string> DATA_BLK_MAXVec= {"BLK_DEFAULTSC", "BLK_READINGSC","BLK_LOOKINGSC","BLK_SLEEPINGSC","BLK_LIGHTSHOWSC"};
    std::unordered_map<std::string, uint16_t> namePosVer = {
        {"scene1", 0},
        {"scene2", 1},
        {"scene3", 2},
        {"scene4", 3},
        {"scene5", 4}
    };
    uint32_t newseq;
};
#endif /* DATA_BLOCK_CENTER_H */