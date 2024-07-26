#include <memory>
#include "DsvPpsIfStruct.h"
#include "glog/logging.h"
#include "trigger/Trigger.h"
#include "trigger/TriggerManager.h"

namespace hht {
namespace datamanager {

TriggerManager::TriggerManagerData::TriggerManagerData() {
    CONTAINER_MAP = {
        {Dsvpps::E_DataLogging1,{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},
        {Dsvpps::E_DataLogging4,{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},
        {Dsvpps::E_DataLogging3,{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},
        {Dsvpps::E_DataLogging5,{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},
        {Dsvpps::E_DataLogging7,{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},
        {Dsvpps::E_ESAInfo,{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},
        {Dsvpps::E_PboxMgrInfo,{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},
    };

    EXTRACTOR_MAP = {
        {"DataLogging1.csmInfo.CSM_SAS_SteeringWheelAngle",{Dsvpps::E_DataLogging1, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging1, csmInfo.CSM_SAS_SteeringWheelAngle))}},
        {"DataLogging1.csmInfo.CSM_SAS_SteeringWheelSpeed",{Dsvpps::E_DataLogging1, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging1, csmInfo.CSM_SAS_SteeringWheelSpeed))}},
        {"DataLogging1.vdcmInfo.ActlGear",{Dsvpps::E_DataLogging1, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging1, vdcmInfo.ActlGear))}},
        {"DataLogging4.longControlOutput.accelReq",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging4, longControlOutput.accelReq))}},
        {"DataLogging4.longControlOutput.unavailableReason",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, longControlOutput.unavailableReason))}},
        {"DataLogging4.longControlOutput.accMode",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, longControlOutput.accMode))}},
        {"DataLogging4.longControlOutput.automaticDisEngagement",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<bool>>(offsetof(Dsvpps::DataLogging4, longControlOutput.automaticDisEngagement))}},
        {"DataLogging4.aebOutput.aecsMode",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, aebOutput.aecsMode))}},
        {"DataLogging4.aebOutput.fcwMode",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, aebOutput.fcwMode))}},
        {"DataLogging4.lksInfo.lksStatus",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, lksInfo.lksStatus))}},
        {"DataLogging4.lksInfo.lksLeftActiveSt",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, lksInfo.lksLeftActiveSt))}},
        {"DataLogging4.lksInfo.lksRightActiveSt",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, lksInfo.lksRightActiveSt))}},
        {"DataLogging4.lcaInfo.warnLeftLCA",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, lcaInfo.warnLeftLCA))}},
        {"DataLogging4.lcaInfo.warnRightLCA",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, lcaInfo.warnRightLCA))}},
        {"DataLogging4.lcaInfo.stateLCA",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, lcaInfo.stateLCA))}},
        {"DataLogging4.rcwInfo.warnRCW",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, rcwInfo.warnRCW))}},
        {"DataLogging4.rcwInfo.stateRCW",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, rcwInfo.stateRCW))}},
        {"DataLogging4.dowInfo.warnFLDOW",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, dowInfo.warnFLDOW))}},
        {"DataLogging4.dowInfo.warnRLDOW",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, dowInfo.warnRLDOW))}},
        {"DataLogging4.dowInfo.warnFRDOW",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, dowInfo.warnFRDOW))}},
        {"DataLogging4.dowInfo.warnRRDOW",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, dowInfo.warnRRDOW))}},
        {"DataLogging4.dowInfo.stateDOW",{Dsvpps::E_DataLogging4, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging4, dowInfo.stateDOW))}},
        {"DataLogging3.lateralControlOutput.strWhlTorqueReq",{Dsvpps::E_DataLogging3, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging3, lateralControlOutput.strWhlTorqueReq))}},
        {"DataLogging3.lateralControlOutput.state",{Dsvpps::E_DataLogging3, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging3, lateralControlOutput.state))}},
        {"DataLogging3.lateralControlOutput.lccUnavailableReason",{Dsvpps::E_DataLogging3, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging3, lateralControlOutput.lccUnavailableReason))}},
        {"DataLogging5.imuSecondary.accelLong",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging5, imuSecondary.accelLong))}},
        {"DataLogging5.imuSecondary.accelLateral",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging5, imuSecondary.accelLateral))}},
        {"DataLogging5.brakeSysInfoESC.MasterCylinderPressure",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging5, brakeSysInfoESC.MasterCylinderPressure))}},
        {"DataLogging5.brakeSysInfoESC.DrvReqFxBrkDomAvail",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging5, brakeSysInfoESC.DrvReqFxBrkDomAvail))}},
        {"DataLogging5.escInfo.TCSIntervention",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging5, escInfo.TCSIntervention))}},
        {"DataLogging5.escInfo.VDCIntervention",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging5, escInfo.VDCIntervention))}},
        {"DataLogging5.vehicleDynamic.VehicleSpeed_ASILD",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging5, vehicleDynamic.VehicleSpeed_ASILD))}},
        {"DataLogging5.apaStatus.apaParkingState",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging5, apaStatus.apaParkingState))}},
        {"DataLogging5.apaStatus.apaSVSActiveSt",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<bool>>(offsetof(Dsvpps::DataLogging5, apaStatus.apaSVSActiveSt))}},
        {"DataLogging5.apaStatus.apaFrontPMAEBSt",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging5, apaStatus.apaFrontPMAEBSt))}},
        {"DataLogging5.apaStatus.apaRearPMAEBSt",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<uint8_t>>(offsetof(Dsvpps::DataLogging5, apaStatus.apaRearPMAEBSt))}},
        {"DataLogging5.apaStatus.apaAVMActivationDistanceFD",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging5, apaStatus.apaAVMActivationDistanceFD))}},
        {"DataLogging5.acuInfo.acuFrontCrashOutputSt",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<bool>>(offsetof(Dsvpps::DataLogging5, acuInfo.acuFrontCrashOutputSt))}},
        {"DataLogging5.acuInfo.acuDriverSideCrashOutputSt",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<bool>>(offsetof(Dsvpps::DataLogging5, acuInfo.acuDriverSideCrashOutputSt))}},
        {"DataLogging5.acuInfo.acuPassengerSideCrashOutputSt",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<bool>>(offsetof(Dsvpps::DataLogging5, acuInfo.acuPassengerSideCrashOutputSt))}},
        {"DataLogging5.acuInfo.acuRearSideCrashOutputSt",{Dsvpps::E_DataLogging5, std::make_shared<Extractor<bool>>(offsetof(Dsvpps::DataLogging5, acuInfo.acuRearSideCrashOutputSt))}},
        {"DataLogging7.apaInfo.apaPASFLDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<uint16_t>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFLDistance))}},
        {"DataLogging7.apaInfo.apaPASFMLDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<uint16_t>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFMLDistance))}},
        {"DataLogging7.apaInfo.apaPASFMRDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<uint16_t>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFMRDistance))}},
        {"DataLogging7.apaInfo.apaPASFRDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<uint16_t>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFRDistance))}},
        {"DataLogging7.apaInfo.apaPASRLDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRLDistance))}},
        {"DataLogging7.apaInfo.apaPASRRDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRRDistance))}},
        {"DataLogging7.apaInfo.apaPASRMLDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRMLDistance))}},
        {"DataLogging7.apaInfo.apaPASRMRDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRMRDistance))}},
        {"DataLogging7.apaInfo.apaSDWFLSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFLSideDistance))}},
        {"DataLogging7.apaInfo.apaSDWFRSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFRSideDistance))}},
        {"DataLogging7.apaInfo.apaSDWRLSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRLSideDistance))}},
        {"DataLogging7.apaInfo.apaSDWRRSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRRSideDistance))}},
        {"DataLogging7.apaInfo.apaSDWFMLSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFMLSideDistance))}},
        {"DataLogging7.apaInfo.apaSDWFMRSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFMRSideDistance))}},
        {"DataLogging7.apaInfo.apaSDWRMLSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRMLSideDistance))}},
        {"DataLogging7.apaInfo.apaSDWRMRSideDistance",{Dsvpps::E_DataLogging7, std::make_shared<Extractor<float>>(offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRMRSideDistance))}},
        {"ESAInfo.egoEgoStatus.velocityX",{Dsvpps::E_ESAInfo, std::make_shared<Extractor<float>>(offsetof(Dsvpps::ESAInfo, egoEgoStatus.velocityX))}},
        {"PboxMgrInfo.pboxMgrIMU.accX",{Dsvpps::E_PboxMgrInfo, std::make_shared<Extractor<double>>(offsetof(Dsvpps::PboxMgrInfo, pboxMgrIMU.accX))}},
        {"PboxMgrInfo.pboxMgrIMU.accY",{Dsvpps::E_PboxMgrInfo, std::make_shared<Extractor<double>>(offsetof(Dsvpps::PboxMgrInfo, pboxMgrIMU.accY))}},
    };
}

void TriggerManager::triggerUpdateHandler(int32_t topic, uint8_t* data, size_t len) {
    if (mLoadSuccess && (topic == (int32_t)Dsvpps::E_DataLogging1 || topic == (int32_t)Dsvpps::E_DataLogging4 ||
                         topic == (int32_t)Dsvpps::E_DataLogging3 || topic == (int32_t)Dsvpps::E_DataLogging5 ||
                         topic == (int32_t)Dsvpps::E_DataLogging7 || topic == (int32_t)Dsvpps::E_ESAInfo ||
                         topic == (int32_t)Dsvpps::E_PboxMgrInfo)) {
        auto it = mContainer.CONTAINER_MAP.find(topic);
        if(it == mContainer.CONTAINER_MAP.end()) {
            LOG(ERROR) << "[TriggerManager::TriggerUpdateHandler] wrong topic: " << topic << ".\n";
            return;
        }

        std::lock_guard<std::mutex> lock(mMtx);
        for (auto&& eval : *std::get<0>(it->second)) {
            auto&& ext = eval.first;
            eval.second->eval(ext->extract(data));
        }

        uint64_t time_point = getCurrentTimestamp();
        for (auto&& trigger : *std::get<1>(it->second)) {
            trigger->update(time_point);
        }
    }
}


}  // namespace datamanager
}  // namespace hht