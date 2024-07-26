#include "trigger/TriggerManager.h"

#include <memory>
#include <set>

#include "DMDefine.h"
#include "glog/logging.h"
#include "trigger/Trigger.h"
#include "yaml-cpp/yaml.h"

namespace hht {
namespace datamanager {

void TriggerManager::start() {
}

void TriggerManager::stop() {
}

bool TriggerManager::loadYaml() {
    YAML::Node config;
    try {
        config = YAML::LoadFile(TRIGGER_CFG_PATH);
        config = config["Triggers"];
    } catch (const std::exception& e) {
        LOG(ERROR) << "[TriggerManager::loadYaml] Failed loading file. Error: " << e.what() << ".\n";
        return false;
    }

    for (YAML::const_iterator it = config.begin(); it != config.end(); ++it) {
        try {
            YAML::Node current = *it;

            int id = current["Id"].as<int>();
            int trigger_times = current["TriggerMaxTimes"].as<int>();

            auto trigger = std::make_shared<Trigger>(id);
            trigger->setMaxTriggerTimes(trigger_times);

            std::string logic = current["Logic"].as<std::string>();
            logic = "(" + logic + ")";

            TriggerAction action;
            action.PostTriggerAcqusitionInterval = current["PostTrigger"].as<uint32_t>();
            action.PreTriggerAcquisitionInterval = current["PreTrigger"].as<uint32_t>();

            YAML::Node evals = current["Evaluators"];

            std::set<std::string> trigger_signals;
            for (YAML::const_iterator eit = evals.begin(); eit != evals.end(); ++eit) {
                YAML::Node eval = *eit;

                std::string name = eval["Name"].as<std::string>();
                std::string policy = eval["Policy"].as<std::string>();
                std::string signal = eval["Signal"].as<std::string>();
                std::string expected = eval["Expected"].as<std::string>();
                uint32_t duration = eval["Duration"].as<uint32_t>();

                // throw on empty, not likely to happen
                Variant exp = processExpected(expected);

                std::shared_ptr<BaseEvaluator> evaluator;
                if (policy == "EqualTo") {
                    evaluator = std::make_shared<Evaluator<EqualTo>>(exp, duration);
                } else if (policy == "NotEqualTo") {
                    evaluator = std::make_shared<Evaluator<NotEqualTo>>(exp, duration);
                } else if (policy == "GreaterThan") {
                    evaluator = std::make_shared<Evaluator<GreaterThan>>(exp, duration);
                } else if (policy == "GreaterThanOrEqualTo") {
                    evaluator = std::make_shared<Evaluator<GreaterThanOrEqualTo>>(exp, duration);
                } else if (policy == "LessThan") {
                    evaluator = std::make_shared<Evaluator<LessThan>>(exp, duration);
                } else if (policy == "LessThanOrEqualTo") {
                    evaluator = std::make_shared<Evaluator<LessThanOrEqualTo>>(exp, duration);
                } else if (policy == "DiffEqualTo") {
                    evaluator = std::make_shared<Evaluator<DiffEqualTo>>(exp, duration);
                } else if (policy == "DiffNotEqualTo") {
                    evaluator = std::make_shared<Evaluator<DiffNotEqualTo>>(exp, duration);
                } else if (policy == "DiffGreaterThan") {
                    evaluator = std::make_shared<Evaluator<DiffGreaterThan>>(exp, duration);
                } else if (policy == "DiffGreaterThanOrEqualTo") {
                    evaluator = std::make_shared<Evaluator<DiffGreaterThanOrEqualTo>>(exp, duration);
                } else if (policy == "DiffLessThan") {
                    evaluator = std::make_shared<Evaluator<DiffLessThan>>(exp, duration);
                } else if (policy == "DiffLessThanOrEqualTo") {
                    evaluator = std::make_shared<Evaluator<DiffLessThanOrEqualTo>>(exp, duration);
                } else {
                    LOG(ERROR) << "[TriggerManager::loadYaml] Failed Parsing. Wrong Policy: " << policy << ".\n";
                    loadDefault();
                    return false;
                }

                trigger->addEvaluator(name, evaluator);
                if(!registerEvaluator(signal, evaluator)) {
                    loadDefault();
                    return false;
                };
                trigger_signals.insert(signal);
            }

            for (auto&& signal : trigger_signals) {
                if(!registerTrigger(signal, trigger)) {
                    loadDefault();
                    return false;
                };
            }

            mTriggers.push_back(trigger);

            trigger->setAction(action);
            if (!trigger->setLogic(logic)) {
                LOG(ERROR) << "[TriggerManager::loadYaml] Failed building logic: " << logic << ".\n";
                loadDefault();
                return false;
            }

            // LOG(INFO) << "[TriggerManager::loadYaml] Register trigger success id: " << id << "\n";
        } catch (const std::exception& e) {
            LOG(ERROR) << "[TriggerManager::loadYaml] Failed Parsing. Error: " << e.what() << ".\n";
            loadDefault();
            return false;
        }
    }

    LOG(INFO) << "[TriggerManager::loadYaml] Load yaml Success. Total No. Triggers: " << mTriggers.size() << "\n";
    mLoadSuccess = true;
    return true;
}

void TriggerManager::loadDefault() {
    LOG(ERROR) << "[TriggerManager::loadDefault] No Active Triggers. " << '\n';
    mContainer = TriggerManagerData();
    // todo
}

void TriggerManager::setNotifier(std::function<void(TriggerInfo)> f) {
    mNotifier = std::make_shared<std::function<void(TriggerInfo)>>(f);
    for (auto&& trigger : mTriggers) {
        trigger->setNotifier(mNotifier);
    }
}

Variant TriggerManager::processExpected(const std::string& expected) {
    if (expected.empty()) {
        throw std::runtime_error("empty expected string");
    }

    if (expected.back() == 'f') {
        // expected.pop_back();
        return Variant((double)std::stod(std::string(expected.begin(), expected.end() - 1)));
    } else {
        return Variant((int)std::stoi(expected));
    }
}

uint64_t TriggerManager::getCurrentTimestamp() {
    timespec time;

    clock_gettime(CLOCK_REALTIME, &time);
    return (int64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}

bool TriggerManager::registerTrigger(const std::string& key, TriggerPtr trigger) {
    auto ext = mContainer.EXTRACTOR_MAP.find(key);
    if (ext == mContainer.EXTRACTOR_MAP.end()) {
        LOG(ERROR) << "[TriggerManager::registerTrigger] wrong key: " << key << ".\n";
        return false;
    }

    TopicId id = std::get<0>(ext->second);

    auto it = mContainer.CONTAINER_MAP.find(id);
    if (it == mContainer.CONTAINER_MAP.end()) {
        LOG(ERROR) << "[TriggerManager::registerTrigger] wrong key: " << key << ".\n";
        return false;

    }

    auto&& container = std::get<1>(it->second);
    if (!container) {
        container = std::make_shared<TriggerContainer>();
    }
    container->push_back(trigger);
    return true;

}

bool TriggerManager::registerEvaluator(const std::string& key, EvaluatorPtr eval) {

    auto ext = mContainer.EXTRACTOR_MAP.find(key);
    if (ext == mContainer.EXTRACTOR_MAP.end()) {
        LOG(ERROR) << "[TriggerManager::registerTrigger] wrong key: " << key << ".\n";
        return false;
    }

    TopicId id = std::get<0>(ext->second);

    auto it = mContainer.CONTAINER_MAP.find(id);
    if (it == mContainer.CONTAINER_MAP.end()) {
        LOG(ERROR) << "[TriggerManager::registerTrigger] wrong key: " << key << ".\n";
        return false;
    }

    auto&& container = std::get<0>(it->second);
    if (!container) {
        container = std::make_shared<EvaluatorContainer>();
    }

    auto && extractor = mContainer.EXTRACTOR_MAP.find(key);
    if (extractor == mContainer.EXTRACTOR_MAP.end()) {
        return false;
    }

    container->push_back({std::get<1>(extractor->second), eval});
    return true;
}

}  // namespace datamanager
}  // namespace hht