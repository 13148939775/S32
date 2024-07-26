/*
 * @author 008555
 * @for mqtt operations' interface
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>

#include <mqtt/async_client.h>

class MyCallback : public virtual mqtt::callback {
public:
  MyCallback(mqtt::async_client& client) 
    : client_(client),
      message_("") {}

  void connected(const mqtt::string& cause) override;

  void connection_lost(const mqtt::string& cause) override;

  void message_arrived(mqtt::const_message_ptr message) override;

  void delivery_complete(mqtt::delivery_token_ptr token) override;

  std::string& GetMessage()
  {
    return message_;
  }

private:
  mqtt::async_client& client_;
  std::string message_;
};

class MqttClient {
public:
    MqttClient(const std::string& serverURI, const std::string& clientId)
        : serverURI_(serverURI), clientId_(clientId),
        mqttClient_(serverURI, clientId),
        myCallBack_(mqttClient_)
        {
           mqttClient_.set_callback(myCallBack_);
        }

    void Connect(const std::string& username, const std::string& pwd, int interval, bool session);
    void DisConnect();
    void Subscribe(const std::string& topic, int qos);
    void UnSubscribe(const std::string& topic);
    void Publish(const std::string& topic, const std::string& payload, int qos);

    std::string& GetMqttRes() {
      return myCallBack_.GetMessage();
    }

private:
    std::string serverURI_;
    std::string clientId_;
    mqtt::async_client mqttClient_; //异步
    MyCallback myCallBack_;

    mqtt::connect_options connectOptions_;
    std::string usrName_;
    std::string password_;
    int interval;
    bool session;
};