
#include "trigger/Trigger.h"

#include <memory>
#include <set>
#include <unordered_map>

#include "glog/logging.h"

namespace hht {
namespace datamanager {

void Trigger::setNotifier(std::shared_ptr<std::function<void(TriggerInfo)>> f) { mNotifier = f; }

void Trigger::setAction(const TriggerAction& action) { mAction = action; }

bool Trigger::setLogic(const std::string& expression) {
    mLogic = LogicNode::build(expression);
    if (!mLogic) {
        LOG(ERROR) << "[Trigger::setLogic] build logic failed : " << expression << "\n";
        return false;
    }
    return true;
}

void Trigger::setMaxTriggerTimes(int nTimes){
    if(nTimes == 0){
        LOG(INFO) << "[Trigger::setMaxTriggerTimes] Trigger Not Working. MaxTriggerTimes: " << nTimes << ".\n";
    }
    else if(nTimes < 0){
        LOG(INFO) << "[Trigger::setMaxTriggerTimes] Trigger Has No Max Time. MaxTriggerTimes: " << nTimes << ".\n";
    }
    else {
        // do nothing
    }
    mMaxTriggerTimes = nTimes;
}


void Trigger::addEvaluator(const std::string& name, std::shared_ptr<BaseEvaluator> evaluator) {
    if (mEvals.count(name)) {
        LOG(ERROR) << "[Trigger::addEvaluator] name exists.\n";
        return;
    }
    mEvals[name] = evaluator;
}

void Trigger::update(uint64_t time_point) {
    auto result = visit(mLogic.get());

    if (result.success) {
        if (result.result && !mStatus) {
            mStatus = true;

            if(mMaxTriggerTimes < 0) {
                // no max trigger max times
            } else if(mMaxTriggerTimes == 0) {
                return;  // limit upload max times
            } else {
                mMaxTriggerTimes--;
            }

            TriggerInfo info;
            info.triggerId = id_;
            info.triggerMs = time_point;
            info.beginMs = time_point - mAction.PreTriggerAcquisitionInterval;
            info.endMs = time_point + mAction.PostTriggerAcqusitionInterval;

            trigger(info);

        } else if (!result.result && mStatus) {
            mStatus = false;
        } else {
            // do nothing
        }
    } else {
        LOG(ERROR) << "[Trigger::update] visit failed.\n";
    }
}

void Trigger::trigger(TriggerInfo info) {
    LOG(INFO) << "[Trigger::trigger] Trigged id_= " << id_ << ".\n";
    if (mNotifier) {
        (*mNotifier)(info);
    } else {
        std::cout << "Triggered id_ = " << id_ << ".\n";
    }
}

Trigger::VisitResult Trigger::visit(LogicNode* current) {
    if (!current) {
        LOG(ERROR) << "[Trigger::visit] current node empty.\n";
        return {};
    }

    auto&& token = current->mToken;

    if (token.type() == TokenType::Field) {
        if (!mEvals.count(token.value())) {
            LOG(ERROR) << "[Trigger::visit] current node empty.\n";
            return {};
        }
        return {true, mEvals[token.value()]->status()};
    } else if (token.type() == TokenType::LogicalAnd) {
        auto l{visit(current->left.get())};
        auto r{visit(current->right.get())};
        return {l.success && r.success, l.result && r.result};
    } else if (token.type() == TokenType::LogicalOr) {
        auto l{visit(current->left.get())};
        auto r{visit(current->right.get())};
        return {l.success && r.success, l.result || r.result};
    } else {
        LOG(ERROR) << "[Trigger::visit] wrong token type.\n";
        return {};
    }
}

}  // namespace datamanager
}  // namespace hht
