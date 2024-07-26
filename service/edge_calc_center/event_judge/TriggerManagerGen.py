import re


DATAMANAGER_STRUCT_LIST = [
    "DataLogging1",
    "DataLogging4",
    "DataLogging3",
    "DataLogging5",
    "DataLogging7",
    "ESAInfo",
    "PboxMgrInfo",
]


STRUCT_INCLUDE_LIST = [
"DataLogging1.csmInfo.CSM_SAS_SteeringWheelAngle",
"DataLogging1.csmInfo.CSM_SAS_SteeringWheelSpeed",
"DataLogging1.vdcmInfo.ActlGear",
"DataLogging3.lateralControlOutput.lccUnavailableReason",
"DataLogging3.lateralControlOutput.state",
"DataLogging3.lateralControlOutput.strWhlTorqueReq",
"DataLogging4.aebOutput.aecsMode",
"DataLogging4.aebOutput.fcwMode",
"DataLogging4.dowInfo.stateDOW",
"DataLogging4.dowInfo.warnFLDOW",
"DataLogging4.dowInfo.warnFRDOW",
"DataLogging4.dowInfo.warnRLDOW",
"DataLogging4.dowInfo.warnRRDOW",
"DataLogging4.lcaInfo.stateLCA",
"DataLogging4.lcaInfo.warnLeftLCA",
"DataLogging4.lcaInfo.warnRightLCA",
"DataLogging4.lksInfo.lksLeftActiveSt",
"DataLogging4.lksInfo.lksRightActiveSt",
"DataLogging4.lksInfo.lksStatus",
"DataLogging4.longControlOutput.accMode",
"DataLogging4.longControlOutput.accelReq",
"DataLogging4.longControlOutput.automaticDisEngagement",
"DataLogging4.longControlOutput.unavailableReason",
"DataLogging4.rcwInfo.stateRCW",
"DataLogging4.rcwInfo.warnRCW",
"DataLogging5.acuInfo.acuDriverSideCrashOutputSt",
"DataLogging5.acuInfo.acuFrontCrashOutputSt",
"DataLogging5.acuInfo.acuPassengerSideCrashOutputSt",
"DataLogging5.acuInfo.acuRearSideCrashOutputSt",
"DataLogging5.apaStatus.apaAVMActivationDistanceFD",
"DataLogging5.apaStatus.apaFrontPMAEBSt",
"DataLogging5.apaStatus.apaParkingState",
"DataLogging5.apaStatus.apaRearPMAEBSt",
"DataLogging5.apaStatus.apaSVSActiveSt",
"DataLogging5.brakeSysInfoESC.DrvReqFxBrkDomAvail",
"DataLogging5.brakeSysInfoESC.MasterCylinderPressure",
"DataLogging5.escInfo.TCSIntervention",
"DataLogging5.escInfo.VDCIntervention",
"DataLogging5.imuSecondary.accelLateral",
"DataLogging5.imuSecondary.accelLong",
"DataLogging5.vehicleDynamic.VehicleSpeed_ASILD",
"DataLogging7.apaInfo.apaPASFLDistance",
"DataLogging7.apaInfo.apaPASFMLDistance",
"DataLogging7.apaInfo.apaPASFMRDistance",
"DataLogging7.apaInfo.apaPASFRDistance",
"DataLogging7.apaInfo.apaPASRLDistance",
"DataLogging7.apaInfo.apaPASRMLDistance",
"DataLogging7.apaInfo.apaPASRMRDistance",
"DataLogging7.apaInfo.apaPASRRDistance",
"DataLogging7.apaInfo.apaSDWFLSideDistance",
"DataLogging7.apaInfo.apaSDWFMLSideDistance",
"DataLogging7.apaInfo.apaSDWFMRSideDistance",
"DataLogging7.apaInfo.apaSDWFRSideDistance",
"DataLogging7.apaInfo.apaSDWRLSideDistance",
"DataLogging7.apaInfo.apaSDWRMLSideDistance",
"DataLogging7.apaInfo.apaSDWRMRSideDistance",
"DataLogging7.apaInfo.apaSDWRRSideDistance",
"ESAInfo.egoEgoStatus.velocityX",
"PboxMgrInfo.pboxMgrIMU.accX",
"PboxMgrInfo.pboxMgrIMU.accY",
]

STRUCT_EXCLUDE_LIST = [
    "header",
]

TRIGGERABLE_TYPES = [
    "uint8_t",
    "uint16_t",
    "uint32_t",
    "uint64_t",
    "int8_t",
    "int16_t",
    "int32_t",
    "int64_t",
    "float",
    "double",
    "bool",
]


class CxxHeaderParser:
    def __init__(self, header_file):
        with open(header_file, "r") as f:
            self.lines = f.readlines()

        self.__parse__()

    def __parse__(self):

        class member:
            def __init__(self, tokens):
                self.type = tokens[0]
                temp = re.split("\[|\]", tokens[1])
                self.name = temp[0]
                self.dim = temp[1] if len(temp)>1 else 0
            def dump(self):
                print("\t", self.type, self.name, self.dim)

        self.structs = {}
        self.enum_names = []
        self.enum_types = []

        current_struct = None
        current_is_enum = False
        for line in self.lines:
            # tokens = re.findall("[\S]+", line)

            tokens = re.split("\n|;|\ ", line)
            tokens = list(filter(None, tokens))

            if "struct" in tokens:
                index = tokens.index("struct")
                name = tokens[index + 1]
                self.structs[name] = []
                current_struct = name
            elif "enum" in tokens:
                enum_index = tokens.index("{") - 1
                enum_name = tokens[enum_index]
                enum_name = re.split(":", enum_name)[0
                                                     ]
                TRIGGERABLE_TYPES.append(enum_name)
                self.enum_types.append(enum_name)
                # print(enum_name)
                current_is_enum = True
                continue
            elif current_is_enum:
                if "}" in tokens:
                    current_is_enum = False
                continue
            elif "//" in tokens:
                continue
            elif current_struct is not None and len(tokens)>=2:
                if tokens[0] in self.enum_types:
                    self.enum_names.append(tokens[1])
                mem = member(tokens[:2])
                self.structs[current_struct].append(mem)

    def get_triggable_members(self, struct, path_prefix=""):
            result = []
            types = []
            for member in self.structs[struct]:
                if member.name in STRUCT_EXCLUDE_LIST:
                    continue
                elif member.type in TRIGGERABLE_TYPES:
                    if member.dim == 0:
                        result.append(".".join([path_prefix, member.name]))
                        if member.type in self.enum_types:
                            # types.append( "Dsvpps::" + struct + "::" + member.type)
                            types.append("uint8_t")
                        else:
                            types.append(member.type)
                    else:
                        continue
                else:
                    if member.dim == 0:
                        result_next, types_next = self.get_triggable_members(member.type, ".".join([path_prefix, member.name]))
                        result = result + result_next
                        types = types + types_next
            return result, types

    def get_triable_items(self):
        self.triggables = []
        self.triggables_types = []
        for struct in DATAMANAGER_STRUCT_LIST:
            triggables, types = self.get_triggable_members(struct, struct)
            self.triggables.extend(triggables)
            self.triggables_types.extend(types)


    def generate_TriggerManagerGen_cpp(self):

        ostr = [
            "#include <memory>",
            "#include \"DsvPpsIfStruct.h\"",
            "#include \"glog/logging.h\"",
            "#include \"trigger/Trigger.h\"",
            "#include \"trigger/TriggerManager.h\"",
            "",
            "namespace hht {",
            "namespace datamanager {",
            ""
        ]

        ostr.extend([
            "TriggerManager::TriggerManagerData::TriggerManagerData() {",
            "    CONTAINER_MAP = {",
        ])

        for item in DATAMANAGER_STRUCT_LIST:
            ostr.extend([
                "        {" + "Dsvpps::E_{},".format(item)  + "{EvaluatorContainerPtr(nullptr), TriggerContainerPtr(nullptr)}},",
            ])

        ostr.extend([
            "    };",
            "",
            "    EXTRACTOR_MAP = {",
        ])

        for item in self.triggables:
            if item not in STRUCT_INCLUDE_LIST:
                continue
            type = self.triggables_types[self.triggables.index(item)]
            tokens = item.split('.')
            ostr.extend([
                "        {" + "\"{}\",".format(item)  + "{" + "Dsvpps::E_{}".format(tokens[0]) + ", std::make_shared<Extractor<{}>>(offsetof(Dsvpps::{}, {}))".format(type, tokens[0], '.'.join(tokens[1:])) + "}},",
            ])

        ostr.extend([
            "    };",
            "}",
            "",
        ])

        '''
        void TriggerManager::TriggerUpdateHandler(int32_t topic, uint8_t* data, size_t len) {
        '''

        ostr.extend([
            "void TriggerManager::triggerUpdateHandler(int32_t topic, uint8_t* data, size_t len) {",
            "if ( mLoadSuccess && ("
        ])


        for struct in DATAMANAGER_STRUCT_LIST:
            ostr.extend([
                "    {} topic == (int32_t) Dsvpps::E_{}".format("" if DATAMANAGER_STRUCT_LIST.index(struct) == 0 else "    ||", struct),
            ])


        ostr.extend([
            "    )){",
            "",
            "        auto it = mContainer.CONTAINER_MAP.find(topic);",
            "        if(it == mContainer.CONTAINER_MAP.end()) {",
            "            LOG(ERROR) << \"[TriggerManager::TriggerUpdateHandler] wrong topic: \" << topic << \".\\n\";",
            "            return;",
            "        }",
            "",
            "        std::lock_guard<std::mutex> lock(mMtx);",
            "        for (auto&& eval : *std::get<0>(it->second)) {",
            "            auto&& ext = eval.first;",
            "            eval.second->eval(ext->extract(data));",
            "        }",
            "",
            "        uint64_t time_point = getCurrentTimestamp();",
            "        for (auto&& trigger : *std::get<1>(it->second)) {",
            "            trigger->update(time_point);",
            "        }",
        ])

        ostr.extend([
            "    }",

            "}",
            ""
        ])



        ostr.extend([
            "",
            "}  // namespace datamanager",
            "}  // namespace hht",
        ])


        with open("TriggerManagerGen.cpp", "w") as f:
            f.write("\n".join(ostr))


    def generate_StructChecker_cpp(self):
        ostr = [
            "#include \"DsvPpsIfStruct.h\"",
            "#include <iostream>",
            "#include <iomanip>",
            "",
            "int main() {",
        ]

        for item in STRUCT_INCLUDE_LIST:
            tokens = item.split('.')
            ostr.extend([
                "    std::cout << std::left << std::setw(100) << \"{}: \" << offsetof(Dsvpps::{}, {}) << std::endl;".format(item, tokens[0], ".".join(tokens[1:]))
            ])

        ostr.extend([
            "    std::cout << \"Success.\" << std::endl;",
            "    return 0;",
            "}",
        ])

        with open("StructChecker.cpp", "w") as f:
            f.write("\n".join(ostr))


if __name__ == "__main__":
    parser = CxxHeaderParser("../../../libs/pps_com/include/DsvPpsIfStruct.h")
    parser.get_triable_items()
    parser.generate_TriggerManagerGen_cpp()
    parser.generate_StructChecker_cpp()

