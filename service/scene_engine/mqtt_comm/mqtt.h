#ifndef MQTT_H
#define MQTT_H

#include <string>
#include <iostream>
#include <mqtt/client.h>

class Mqtt {
public:
    static Mqtt& GetInstance()
    {
        static Mqtt mq;
        return mq;
    }

    int MqttGet();
    
    std::string GetSceneID()
    {
        return sceneID_;
    }

    void SetMqttRun(bool sign)
    {
        mqtt_run_ = sign;
    }
private:
    const std::string SERVER_ADDRESS = "tcp://10.131.129.226:1883";  // Mosquitto测试服务器
    const std::string CLIENT_ID = "HRYTTESTVINMGM270";  // 客户端ID
    const std::string TOPIC = "tsp_idcm_HRYTTESTVINMGM270_dev"; // 订阅的主题 tsp_idcm_Vin_dev
    const int QOS = 2;
    static uint32_t mqttcount_;
    std::string sceneID_;
    bool mqtt_run_ = true;
};
#endif