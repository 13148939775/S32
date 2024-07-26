/*
 * @author T001285 
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <cstdio>
#include <nlohmann/json.hpp>
#include <node_log.h>

using json = nlohmann::json;

int ResCheck(int type,std::string& result) 
{
    FILE* pipe = nullptr;;
    int rfd = -1;

    if (0 == type) {
        pipe = popen("ifconfig -a", "r");
        if (!pipe) {
            HHT_LOG(WARNING) << "popen() ifconfig -a  failed!";
            return -1;
        }
    }
    else if (1 == type) {
        pipe = popen("route -n", "r");
        if (!pipe) {
            HHT_LOG(WARNING) << "popen() reoute -n failed!";
            return -1;
        }
    }
    else if (2 == type) {
        rfd = open("/etc/resolv.conf", O_RDONLY);
        if ( !rfd ) {
            HHT_LOG(WARNING) << "open /etc/resolve.conf failed!";
            return -1;
        }
    }
    else if (3 == type) {
        pipe = popen("ping -c 4 www.baidu.com", "r");
        if (!pipe) {
            HHT_LOG(WARNING) << "popen() reoute -n failed!";
            return -1;
        }
    }

    char buffer[128];
    result.clear();
    int bytesRead=0; 

    if (2 == type) {
        while ((bytesRead = read(rfd, buffer, sizeof(buffer))) > 0) {
            result.append(buffer, bytesRead);
        }
        if (bytesRead == -1) {
            HHT_LOG(WARNING) << "read /etc/resolve.conf failed!";
            close(rfd);  // 关闭文件描述符
        }
        close(rfd);  // 关闭文件描述符
    }
    else {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
           result += buffer;
         }
        pclose(pipe);
    }

    return 0;
}

int main() {

    HHT::NodeLog node("netConfig");
    node.InitLog(LOG_LEVEL_INFO,LOG_LEVEL_INFO);

    system("./ut_run.sh");

    // 读取JSON配置文件
    std::ifstream configFile("net_config.json");
    if (!configFile) {
        HHT_LOG(WARNING)<<"open net_config.json failed";
        return -1;
    }

    json configAll;
    configFile >> configAll;
    configFile.close();

    // 获取 "tboxtype" 字段的值
    std::string selectedType = configAll["tboxType"];

    json config;
    if (selectedType == "VC1") {
        config = configAll["VC1"];
    }
    else if (selectedType == "AN1") {
        config = configAll["AN1"];
    }
    else {
        HHT_LOG(WARNING)<<"no type matched then exit!";
        return -1;
    }

    // 从JSON配置中提取网卡名
    std::string ethName;
    if (config.contains("ethName")) {
        ethName = config["ethName"];
    } else {
        HHT_LOG(WARNING)<<"there is no ethName information in  net_config.json";
        return -1;
    }

    // 从JSON配置中提取IP地址
    std::string ipAddress;
    if (config.contains("ipAddress")) {
        ipAddress = config["ipAddress"];
    } else {
        HHT_LOG(WARNING)<<"there is no ipAddress information in  net_config.json";
        return -1;
    }

    // 从JSON配置中提取netmask地址
    std::string netmask;
    if (config.contains("netmask")) {
        netmask = config["netmask"];
    } else {
        HHT_LOG(WARNING)<<"there is no netmask information in  net_config.json";
        return -1;
    }


    // 从JSON配置中提取gateway地址
    std::string gatewayAddress;
    if (config.contains("gatewayAddress")) {
        gatewayAddress = config["gatewayAddress"];
    } else {
        HHT_LOG(WARNING)<<"there is no  gatewayAddress information in  net_config.json";
        return -1;
    }
    // 输出IP地址和MAC地址
    HHT_LOG(INFO) << "配置文件中以太网卡名: " << ethName;
    HHT_LOG(INFO) << "配置文件中IP地址: " << ipAddress;
    HHT_LOG(INFO) << "配置文件中netmask地址: " << netmask;
    HHT_LOG(INFO) << "配置文件中gateway地址: " << gatewayAddress;

    // 构建要执行的命令
    char command[100];
    // 1.配置ip地址
    snprintf(command, sizeof(command), "ifconfig %s %s netmask %s",ethName.c_str(),ipAddress.c_str(),netmask.c_str());
    int result; 
    result = system(command);
    if (result == 0) {
        HHT_LOG(INFO)<<"modify ipAddress successed! current ipAddress:"<<ipAddress<<" netmask:"<<netmask;
    } else {
        HHT_LOG(INFO)<<"modify ipAddress failed! then exit";
     /*   return -1;
      *   假如配置失败，不退出程序
      */
    }

    std::string res;
    if (!ResCheck(0,res)) {
        HHT_LOG(INFO) << "-----Ip&netmask check result blew-----"; 
        HHT_LOG(INFO) << res;
    }
    else {
        HHT_LOG(INFO) << "ResCheck failed";
    }


    // 2.配置网关
    snprintf(command, sizeof(command), "route add default gw %s",gatewayAddress.c_str());
    result = system(command);
    if (result == 0) {
        HHT_LOG(INFO)<<"modify gatewayAddress successed! the current gatewayAddress is:"<<gatewayAddress;
    } else {
        HHT_LOG(INFO)<<"modify gatewayAddress failed! then exit";
     /*   return -1;
      *   假如配置失败，不应该退出程序
      */
    }

    if (!ResCheck(1,res)) {
        HHT_LOG(INFO) << "-----GataWay check result blew-----"; 
        HHT_LOG(INFO) << res;
    }
    else {
        HHT_LOG(INFO) << "ResCheck failed";
    }

    // 3.配置DNS
    std::vector<std::string> vecDnsServers = config["dns_servers"];

    std::string filePath("/etc/resolv.conf");
    int fd = open(filePath.c_str(), O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        HHT_LOG(ERROR) << filePath << "open failed!!";
        return -1;
    }

    for (const auto& iter : vecDnsServers) {
       std::string dnsInfo = "nameserver " + iter + "\n"; 
       int size = write(fd, dnsInfo.c_str(), dnsInfo.length() );
       if (size == dnsInfo.length()) {
           HHT_LOG(INFO) << "dnsServer address has been set:" << dnsInfo;
       }
    }

    if (!ResCheck(2,res)) {
        HHT_LOG(INFO) << "-----DNS check result blew-----"; 
        HHT_LOG(INFO) << res;
    }
    else {
        HHT_LOG(INFO) << "ResCheck failed";
    }

    if (!ResCheck(3,res)) {
        HHT_LOG(INFO) << "-----Ping baidu  check result blew-----"; 
        HHT_LOG(INFO) << res;
    }
    else {
        HHT_LOG(INFO) << "ResCheck failed";
    }
    close(fd);

}

