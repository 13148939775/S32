#include "mqtt_client.h"
#include "node_log.h"
#include <iostream>

void MyCallback::connected(const mqtt::string& cause) {
    HHT_LOG(INFO) << "Connected, cause: " << cause << std::endl;
}

void MyCallback::connection_lost(const mqtt::string& cause){
    HHT_LOG(INFO) << "Connection lost, cause: " << cause << std::endl;
// Here you might want to try reconnecting, depending on your use case.
}

void MyCallback::message_arrived(mqtt::const_message_ptr message) {
    HHT_LOG(INFO) << "Message arrived: " << message->get_payload_str() << std::endl;
    message_ = message->get_payload_str();
}

void MyCallback::delivery_complete(mqtt::delivery_token_ptr token) {
    HHT_LOG(INFO)<< "Delivery completed for token: " << token->get_message_id() << std::endl;
}

void MqttClient::Connect(const std::string& username, const std::string& pwd, int interval, bool session) {
    connectOptions_.set_user_name(username);
    connectOptions_.set_password(pwd);
    connectOptions_.set_keep_alive_interval(interval);
    connectOptions_.set_clean_session(session);
    mqttClient_.connect(connectOptions_)->wait();
}

void MqttClient::DisConnect() {
    mqttClient_.disconnect()->wait();
}

void MqttClient::Subscribe(const std::string& topic, int qos) {
    mqttClient_.subscribe(topic, qos)->wait();
}

void MqttClient::UnSubscribe(const std::string& topic) {
    mqttClient_.unsubscribe(topic)->wait();
}

void MqttClient::Publish(const std::string& topic, const std::string& payload, int qos) {
    mqtt::message_ptr msg = mqtt::make_message(topic, payload);
    msg->set_qos(qos);
    mqttClient_.publish(msg)->wait();
}