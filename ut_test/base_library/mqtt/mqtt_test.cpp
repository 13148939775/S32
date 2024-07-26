#include "../mqtt_client.h"

int main(){
    // 创建MQTT客户端
    MqttClient client("tcp://10.131.129.226:1883", "HRYTTESTVINMGM270");

    
    // 连接到MQTT服务端
    client.connect("messagecenterdev", "public", 60, true);

    // 订阅一个主题，QoS为1
    //QOS = 0,1,2
    client.subscribe("tsp_idcm_HRYTTESTVINMGM270_dev", 1);

    // 发布消息到刚刚订阅的主题，QoS为1
    //client.publish("test/topic", "Hello MQTT", 1);

    // 等待一段时间以获取服务器的返回
    std::this_thread::sleep_for(std::chrono::seconds(20));

    std::cout<<"get mqtt result: "<<client.GetMqttRes()<<std::endl;

    // 取消订阅和断开连接
    client.unsubscribe("tsp_idcm_HRYTTESTVINMGM270_dev");
    client.disconnect();

    return 0;
}   