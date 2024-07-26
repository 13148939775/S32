#include "mqtt.h"

uint32_t Mqtt::mqttcount_ = 0;

class callback : public virtual mqtt::callback
{
public:
    void connection_lost(const std::string &cause) override
    {
        std::cout << "\n连接中断：" << cause << std::endl;
    }

    void delivery_complete(mqtt::delivery_token_ptr tok) override
    {
        std::cout << "\n消息传送完成：" << tok->get_message_id() << std::endl;
    }

    void message_arrived(mqtt::const_message_ptr msg) override
    {
        std::cout << "\n接收到新消息：" << std::endl;
        std::cout << "主题：" << msg->get_topic() << std::endl;
        std::cout << "负载：" << msg->to_string() << std::endl;
        mesg_ = msg->to_string();
    }

    std::string& GetMesg()
    {
        return mesg_;
    }
private:
    std::string mesg_;
};

int Mqtt::MqttGet()
{
    mqtt::client client(SERVER_ADDRESS, CLIENT_ID);

    callback cb;
    client.set_callback(cb);

    mqtt::connect_options connOpts;
    //用于身份验证和授权
    connOpts.set_user_name("messagecenterdev");
    connOpts.set_password("public");
    //设置心跳间隔，以确保客户端和代理服务器之间保持持久连接
    connOpts.set_keep_alive_interval(60);
    //如果设置为 true，则代表当客户端断开连接时所有订阅和 QoS 等级设置都会被删除。
    //如果设置为 false，则代表客户端保留面向服务器的订阅
    connOpts.set_clean_session(true);

    try
    {
        std::cout << "连接到服务器：" << SERVER_ADDRESS << std::endl;
        client.connect(connOpts);

        std::cout << "订阅主题：" << TOPIC << std::endl;
        client.subscribe(TOPIC, QOS);
        
        // int count = 0;
        while (mqtt_run_)
        {
            client.start_consuming();  //接收消息函数,自动调用回调类中函数
            std::this_thread::sleep_for(std::chrono::seconds(5));
            sceneID_ = cb.GetMesg();
            if(sceneID_ != "")
            {
                std::cout<<"hello world"<<std::endl;
            }
            ++mqttcount_;
            std::cout << "等待场景下发计数" << mqttcount_ << std::endl;
        }

        client.unsubscribe(TOPIC);
        client.disconnect();
    }
    catch (const mqtt::exception &exc)
    {
        std::cerr << "MQTT 异常：" << exc.what() << std::endl;
        return 1;
    }

    return 0;
}
