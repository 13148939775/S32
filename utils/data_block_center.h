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

class DataBlockCenter {
    enum {
        DATA_BLOCK_NEAR_CAR,
        DATA_BLOCK_ENTRY_CAR,
        DATA_BLOCK_LEAVE_CAR,
        DATA_BLOCK_ENABLE_READING,
        DATA_BLOCK_DISABLE_READING,
        DATA_BLOCK_ENABLE_LOOKINGFOR,
        DATA_BLOCK_DISABLE_LOOKINGFOR,
        DATA_BLOCK_MAX_ID
    };
public:
    class Observer {
    public:
        virtual void OnNotify(DataBlockCenter& dbc);
    };
    bool AttachObserver(size_t blk, Observer* ob)
    {
        auto res = observers_[blk].insert(ob);
        return res.second;
    }

    bool RemoveObserver(size_t blk, Observer* ob)
    {
        auto res = observers_[blk].erase(ob);
        return res == 1;
    }

    void Notify()
    {
        std::vector<Observer*> localObservers;
        
        for (int i = 0; i < DATA_BLOCK_MAX_ID; ++i) {
            if (!blkFlag_.test(i)) {
                continue; // this event is not occur
            }
        }
    }
private:
    std::bitset<DATA_BLOCK_MAX_ID> blkFlag_;
    std::unordered_map<size_t, std::unordered_set<Observer*>> observers_;
};
#endif /* DATA_BLOCK_CENTER_H */
