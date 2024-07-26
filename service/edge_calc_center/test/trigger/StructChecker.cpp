#include "DsvPpsIfStruct.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::left << std::setw(100) << "DataLogging1.csmInfo.CSM_SAS_SteeringWheelAngle: " << offsetof(Dsvpps::DataLogging1, csmInfo.CSM_SAS_SteeringWheelAngle) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging1.csmInfo.CSM_SAS_SteeringWheelSpeed: " << offsetof(Dsvpps::DataLogging1, csmInfo.CSM_SAS_SteeringWheelSpeed) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging1.vdcmInfo.ActlGear: " << offsetof(Dsvpps::DataLogging1, vdcmInfo.ActlGear) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging3.lateralControlOutput.lccUnavailableReason: " << offsetof(Dsvpps::DataLogging3, lateralControlOutput.lccUnavailableReason) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging3.lateralControlOutput.state: " << offsetof(Dsvpps::DataLogging3, lateralControlOutput.state) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging3.lateralControlOutput.strWhlTorqueReq: " << offsetof(Dsvpps::DataLogging3, lateralControlOutput.strWhlTorqueReq) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.aebOutput.aecsMode: " << offsetof(Dsvpps::DataLogging4, aebOutput.aecsMode) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.aebOutput.fcwMode: " << offsetof(Dsvpps::DataLogging4, aebOutput.fcwMode) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.dowInfo.stateDOW: " << offsetof(Dsvpps::DataLogging4, dowInfo.stateDOW) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.dowInfo.warnFLDOW: " << offsetof(Dsvpps::DataLogging4, dowInfo.warnFLDOW) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.dowInfo.warnFRDOW: " << offsetof(Dsvpps::DataLogging4, dowInfo.warnFRDOW) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.dowInfo.warnRLDOW: " << offsetof(Dsvpps::DataLogging4, dowInfo.warnRLDOW) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.dowInfo.warnRRDOW: " << offsetof(Dsvpps::DataLogging4, dowInfo.warnRRDOW) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.lcaInfo.stateLCA: " << offsetof(Dsvpps::DataLogging4, lcaInfo.stateLCA) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.lcaInfo.warnLeftLCA: " << offsetof(Dsvpps::DataLogging4, lcaInfo.warnLeftLCA) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.lcaInfo.warnRightLCA: " << offsetof(Dsvpps::DataLogging4, lcaInfo.warnRightLCA) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.lksInfo.lksLeftActiveSt: " << offsetof(Dsvpps::DataLogging4, lksInfo.lksLeftActiveSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.lksInfo.lksRightActiveSt: " << offsetof(Dsvpps::DataLogging4, lksInfo.lksRightActiveSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.lksInfo.lksStatus: " << offsetof(Dsvpps::DataLogging4, lksInfo.lksStatus) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.longControlOutput.accMode: " << offsetof(Dsvpps::DataLogging4, longControlOutput.accMode) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.longControlOutput.accelReq: " << offsetof(Dsvpps::DataLogging4, longControlOutput.accelReq) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.longControlOutput.automaticDisEngagement: " << offsetof(Dsvpps::DataLogging4, longControlOutput.automaticDisEngagement) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.longControlOutput.unavailableReason: " << offsetof(Dsvpps::DataLogging4, longControlOutput.unavailableReason) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.rcwInfo.stateRCW: " << offsetof(Dsvpps::DataLogging4, rcwInfo.stateRCW) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging4.rcwInfo.warnRCW: " << offsetof(Dsvpps::DataLogging4, rcwInfo.warnRCW) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.acuInfo.acuDriverSideCrashOutputSt: " << offsetof(Dsvpps::DataLogging5, acuInfo.acuDriverSideCrashOutputSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.acuInfo.acuFrontCrashOutputSt: " << offsetof(Dsvpps::DataLogging5, acuInfo.acuFrontCrashOutputSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.acuInfo.acuPassengerSideCrashOutputSt: " << offsetof(Dsvpps::DataLogging5, acuInfo.acuPassengerSideCrashOutputSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.acuInfo.acuRearSideCrashOutputSt: " << offsetof(Dsvpps::DataLogging5, acuInfo.acuRearSideCrashOutputSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.apaStatus.apaAVMActivationDistanceFD: " << offsetof(Dsvpps::DataLogging5, apaStatus.apaAVMActivationDistanceFD) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.apaStatus.apaFrontPMAEBSt: " << offsetof(Dsvpps::DataLogging5, apaStatus.apaFrontPMAEBSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.apaStatus.apaParkingState: " << offsetof(Dsvpps::DataLogging5, apaStatus.apaParkingState) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.apaStatus.apaRearPMAEBSt: " << offsetof(Dsvpps::DataLogging5, apaStatus.apaRearPMAEBSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.apaStatus.apaSVSActiveSt: " << offsetof(Dsvpps::DataLogging5, apaStatus.apaSVSActiveSt) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.brakeSysInfoESC.DrvReqFxBrkDomAvail: " << offsetof(Dsvpps::DataLogging5, brakeSysInfoESC.DrvReqFxBrkDomAvail) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.brakeSysInfoESC.MasterCylinderPressure: " << offsetof(Dsvpps::DataLogging5, brakeSysInfoESC.MasterCylinderPressure) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.escInfo.TCSIntervention: " << offsetof(Dsvpps::DataLogging5, escInfo.TCSIntervention) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.escInfo.VDCIntervention: " << offsetof(Dsvpps::DataLogging5, escInfo.VDCIntervention) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.imuSecondary.accelLateral: " << offsetof(Dsvpps::DataLogging5, imuSecondary.accelLateral) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.imuSecondary.accelLong: " << offsetof(Dsvpps::DataLogging5, imuSecondary.accelLong) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging5.vehicleDynamic.VehicleSpeed_ASILD: " << offsetof(Dsvpps::DataLogging5, vehicleDynamic.VehicleSpeed_ASILD) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASFLDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFLDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASFMLDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFMLDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASFMRDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFMRDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASFRDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASFRDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASRLDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRLDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASRMLDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRMLDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASRMRDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRMRDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaPASRRDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaPASRRDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWFLSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFLSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWFMLSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFMLSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWFMRSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFMRSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWFRSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWFRSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWRLSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRLSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWRMLSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRMLSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWRMRSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRMRSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "DataLogging7.apaInfo.apaSDWRRSideDistance: " << offsetof(Dsvpps::DataLogging7, apaInfo.apaSDWRRSideDistance) << std::endl;
    std::cout << std::left << std::setw(100) << "ESAInfo.egoEgoStatus.velocityX: " << offsetof(Dsvpps::ESAInfo, egoEgoStatus.velocityX) << std::endl;
    std::cout << std::left << std::setw(100) << "PboxMgrInfo.pboxMgrIMU.accX: " << offsetof(Dsvpps::PboxMgrInfo, pboxMgrIMU.accX) << std::endl;
    std::cout << std::left << std::setw(100) << "PboxMgrInfo.pboxMgrIMU.accY: " << offsetof(Dsvpps::PboxMgrInfo, pboxMgrIMU.accY) << std::endl;
    std::cout << "Success." << std::endl;
    return 0;
}