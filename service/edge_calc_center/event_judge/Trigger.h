/*
 * @author 007313 008196
 * @for Can Data handler trategy, storage file and upload
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HHT_DATAMANAGER_TRIGGER_H
#define HHT_DATAMANAGER_TRIGGER_H

#include <memory>
#include <unordered_map>

#include "DMDefine.h"
#include "trigger/Evaluator.h"
#include "trigger/LogicNode.h"

namespace HHT {
namespace DataManager {

struct TriggerAction {
    uint32_t PreTriggerAcquisitionInterval{0};
    uint32_t PostTriggerAcqusitionInterval{0};
};

class Trigger {
private:
    struct VisitResult {
        bool success{false};
        bool result{false};
    };

public:
    Trigger(int id) : id_(id) { };

    void setNotifier(std::shared_ptr<std::function<void(TriggerInfo)>> f);

    void setAction(const TriggerAction& action);

    bool setLogic(const std::string& expression);

    void setMaxTriggerTimes(int nTimes);

    void addEvaluator(const std::string& name, std::shared_ptr<BaseEvaluator> evaluator);

    void update(uint64_t time_point);

    void trigger(TriggerInfo info);

    VisitResult visit(LogicNode* current);

    // must filter abnormal data befer TrendJundge
    void Filter(PayLoad& data);

    // whether cur some event is occured or willing occur
    void TrendResult(InpendA, IndpendB, Result , Payload& data);

private:
    int id_;
    int mMaxTriggerTimes{0};
    bool mStatus{false};
    TriggerAction mAction;
    std::shared_ptr<std::function<void(TriggerInfo)>> mNotifier{nullptr};
    std::unique_ptr<LogicNode> mLogic{nullptr};
    std::unordered_map<std::string, std::shared_ptr<BaseEvaluator>> mEvals;
};

}  // namespace datamanager
}  // namespace hht

#endif