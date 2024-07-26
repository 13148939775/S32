#ifndef HHTPRIORITYQUEUE_H
#define HHTPRIORITYQUEUE_H

#include <list>

#include "HhtBasicDef.h"

/***********************************************
 *         [begin                               end)
 * values :[-10][-10][0][0][0][0][1][1][1][5][5]
 *           ^        ^           ^        ^
 *           |        |           |        |
 * headers:[-10]     [0]         [1]      [5]
 *         [begin                            end)
************************************************/
namespace HHT {

template<typename ValueType>
class PriorityQueue {
private:
    typedef std::list<ValueType> VList;
    typedef typename VList::iterator VIterator;

    struct Header {
        int32_t priority;
        VIterator vit;
    };

    typedef std::list<Header> HList;

public:
    void push(const ValueType& value, int32_t priority) {
        auto it = mHeaders.begin();
        for (; it != mHeaders.end(); ++it) {
            if (it->priority >= priority) {
                break;
            }
        }

        if (mHeaders.end() == it) {
            VIterator insertIt = mValues.insert(mValues.end(), value);
            mHeaders.push_back({priority, insertIt});
        } else {
            VIterator insertIt = mValues.insert(it->vit, value);
            if (it->priority == priority) {
                it->vit = insertIt;
            } else {
                mHeaders.insert(it, {priority, insertIt});
            }
        }
    }

    void push(const ValueType& value) { push(value, Pri_Default); }

    ValueType pop() {
        if (isEmpty()) {
            return ValueType();
        }

        ValueType value = mValues.back();
        auto vit = mValues.end();
        --vit;

        if (mHeaders.back().vit == vit) {
            mHeaders.pop_back();
        }

        mValues.pop_back();
        return value;
    }

    int32_t curPriority() const {
        if (isEmpty()) {
            return Pri_Default;
        }

        return mHeaders.back().priority;
    }

    bool isEmpty() const { return mValues.size() == 0;}
    size_t size() const { return mValues.size(); }
    size_t priorityCount() const { return mHeaders.size(); }

protected:
    VList mValues;
    HList mHeaders;
};
}










#endif // HHTPRIORITYQUEUE_H
