#ifndef HHT_DATAMANAGER_TRIGGERMANAGER_H
#define HHT_DATAMANAGER_TRIGGERMANAGER_H

#include <memory>
#include <vector>
#include <tuple>

#include "DMDefine.h"
#include "trigger/Extractor.h"
#include "trigger/Trigger.h"

namespace hht {
namespace datamanager {

class TriggerManager {
public:
typedef std::shared_ptr<BaseExtractor> ExtractorPtr;

typedef std::shared_ptr<BaseEvaluator> EvaluatorPtr;
typedef std::vector<std::pair<ExtractorPtr&, EvaluatorPtr>> EvaluatorContainer;
typedef std::shared_ptr<EvaluatorContainer> EvaluatorContainerPtr;

typedef std::shared_ptr<Trigger> TriggerPtr;
typedef std::vector<TriggerPtr> TriggerContainer;
typedef std::shared_ptr<TriggerContainer> TriggerContainerPtr;

typedef int32_t TopicId;

struct TriggerManagerData {

    TriggerManagerData();

    std::unordered_map<int32_t, std::tuple<EvaluatorContainerPtr, TriggerContainerPtr>> CONTAINER_MAP;
    std::unordered_map<std::string, std::tuple<TopicId, ExtractorPtr>> EXTRACTOR_MAP;

};

public:
    void start();
    void stop();

    bool loadYaml();

    void setNotifier(std::function<void(TriggerInfo)> f);

    void triggerUpdateHandler(int32_t topic, uint8_t* data, size_t len);

private:

    void loadDefault();
    bool registerEvaluator(const std::string& key, EvaluatorPtr eval);
    bool registerTrigger(const std::string& key, TriggerPtr trigger);
    Variant processExpected(const std::string& expected);
    uint64_t getCurrentTimestamp();

private:
    bool mLoadSuccess{false};
    TriggerManagerData mContainer;

    std::mutex mMtx;

    std::shared_ptr<std::function<void(TriggerInfo)>> mNotifier{nullptr};
    std::vector<std::shared_ptr<Trigger>> mTriggers;
};
}  // namespace datamanager
}  // namespace hht
#endif