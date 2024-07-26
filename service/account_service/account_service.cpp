/*
 * @author 008584
 * @for account_service
 * @version 1.0
 * @date 2023-11-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <thread>
#include <fstream>

#include "node_log.h"
#include "mqtt/async_client.h"
#include "mqtt/connect_options.h"
#include "nlohmann/json.hpp"
#include "utils.h"
#include "macros.h"
#include "http_operator.h"
#include "sqlite_operator.h"

nlohmann::json global_data;

int main()
{
    // 读取配置文件
    std::ifstream file("config.json");
    global_data = nlohmann::json::parse(file);
    HHT_LOG(INFO) << "global_data: " << global_data << std::endl;

    // 启动mqtt消息监听线程
    // std::thread mqttThread(MqttGateway);

    // 初始化数据库表
    HHT::SqliteOperatorModel::Init(global_data["DB_NAME"]);
    HHT::SqliteOperator::GetClient()->Exec(CREATE_ACCOUNT_BASE_TABLE);
    HHT::SqliteOperator::GetClient()->Exec(CREATE_ACCOUNT_AUTHORIZE_TABLE);
    HHT::SqliteOperatorModel userModel;
    HHT::SqliteOperatorCols c1;

    c1.Clear();
    c1.AddInstance(ACCOUNT_AUTHORIZE_ITEMS, ACCOUNT_AUTHORIZE_DATA_TYPE, 1, 1, 1, 1, 10000000, 99999999);
    userModel.Table("ACCOUNT_AUTHORIZE").Insert(c1).Exec();

    c1.Clear();
    c1.AddInstance(ACCOUNT_AUTHORIZE_ITEMS, ACCOUNT_AUTHORIZE_DATA_TYPE, 2, 1, 0, 1, 10000000, 99999999);
    userModel.Table("ACCOUNT_AUTHORIZE").Insert(c1).Exec();

    c1.Clear();
    c1.AddInstance(ACCOUNT_AUTHORIZE_ITEMS, ACCOUNT_AUTHORIZE_DATA_TYPE, 3, 1, 1, 0, 10000000, 99999999);
    userModel.Table("ACCOUNT_AUTHORIZE").Insert(c1).Exec();

    HHT::SqliteOperatorInPars squery;
    squery.Add(0);
    HHT::SqliteOperatorRows userComs = userModel.Table("ACCOUNT_AUTHORIZE").Select("REMOTE_CONTROL,LOCATE,ALBUM").Where("ID > ?").FindAlls(squery);

    squery.Clear();
    squery.Add("2");
    squery.Add("2");
    squery.Add("1");
    userModel.Table("ACCOUNT_AUTHORIZE").Update("REMOTE_CONTROL=?,LOCATE=?").Where("ID = ?").Exec(squery);

    squery.Clear();
    squery.Add(0);
    userComs = userModel.Table("ACCOUNT_AUTHORIZE").Select("REMOTE_CONTROL,LOCATE,ALBUM").Where("ID > ?").FindAlls(squery);

    userModel.Table("ACCOUNT_AUTHORIZE").Del().Where("ID = 1").Exec();

    squery.Clear();
    squery.Add(0);
    userComs = userModel.Table("ACCOUNT_AUTHORIZE").Select("REMOTE_CONTROL,LOCATE,ALBUM").Where("ID > ?").FindAlls(squery);

    //通过网络获取图片并转换成base64字符串
    std::string url = "https://img95.699pic.com/xsj/1j/ho/63.jpg%21/fw/700/watermark/url/L3hzai93YXRlcl9kZXRhaWwyLnBuZw/align/southeast";
    std::string base64Image = DownloadAndEncodeImage(url);
  
    c1.Clear();
    c1.AddInstance(ACCOUNT_BASE_ITEMS, ACCOUNT_BASE_DATA_TYPE, 1, std::string("13322225555"), std::string("Tom"), base64Image, std::string("Tommy"), \
    1, std::string("NY"), std::string("IT"), std::string("2000-01-01"), std::string("HIPHI Z"), 1, 2, std::string("123456"), 1, std::string("123456"), \
    std::string("123456"), std::string("123456"), std::string("123456"), 1);
    userModel.Table("ACCOUNT_BASE").Insert(c1).Exec();

    squery.Clear();
    squery.Add(0);
    userComs = userModel.Table("ACCOUNT_BASE").Select("HEAD,PIN_CODE").Where("ID > ?").FindAlls(squery);

    //解码base64并存成图片文件
    std::string decoded_string = Base64Decode(base64Image);
    std::ofstream img_file("output.jpg", std::ios::binary);
    img_file.write(decoded_string.c_str(), decoded_string.size());

    // 移植后重写dds
    // DDSOperator* dds_operator = new(DDSOperator);
    // BodyDomain::BdArm_Get_struct data;
    // dds_operator->publishMessage("test_topic", data);

    // mqttThread.join();

    // 使用GET方法访问RESTful API, 并打印响应的JSON数据
    std::string response = HttpOperator::SendGetRequest("https://www.baidu.com/");
    std::cout << "get_response: " << response << std::endl;
    // nlohmann::json jsonObject_1 = nlohmann::json::parse(response);
    // std::cout << "GET response JSON: " << jsonObject_1 << std::endl;

    // 使用POST方法访问RESTful API, 并打印响应的JSON数据
    std::string postData = "{\"key\": \"value\"}";
    response = HttpOperator::SendPostRequest("https://www.baidu.com/", postData);
    std::cout << "post_response: " << response << std::endl;
    // nlohmann::json jsonObject_2 = nlohmann::json::parse(response);
    // std::cout << "POST response JSON: " << jsonObject_2 << std::endl;

    return 0;
}



// 2023/11/22 弃用MQTT, 拟改为DDS
/*
class callback : public virtual mqtt::callback {
public:
    void connection_lost(const mqtt::string& cause) override
    {
        HHT_LOG(INFO) << "Connection lost: " << cause;
    }

    void message_arrived(mqtt::const_message_ptr message) override
    {
        HHT_LOG(INFO) << "Message arrived";
        std::string topic = message->get_topic();
        std::string payload = message->to_string();

        nlohmann::json j = nlohmann::json::parse(payload);

        HHT_LOG(INFO) << "entire json: " << j << std::endl;
        HHT_LOG(INFO) << "header-ack: " << j["header"]["ack"] << std::endl;

        uint64_t superId = j["SuperID"];
        uint8_t reqType = j["Type"];
        uint8_t property = j["Property"];
        uint8_t bussinessId = j["BussinessID"];

        switch reqType {
            case 0x03:
                //车辆授权逻辑
            case 0x04:
                //取消授权逻辑
            case 0x05:
                //授权禁用逻辑
            case 0x06:
                //属性变更逻辑
        }
    }

    void delivery_complete(mqtt::delivery_token_ptr token) override
    {
        HHT_LOG(INFO) << "Delivery complete";
    }
};


void MqttGateway()
{
    mqtt::async_client client(global_data["MQTT_SERVER_ADDRESS"], global_data["MQTT_CLIENT_ID"]);
    callback cb;
    client.set_callback(cb);

    mqtt::connect_options conn_opts;
    conn_opts.set_keep_alive_interval(ALIVE_INTERVAL);
    conn_opts.set_clean_session(true);
    conn_opts.set_user_name(global_data["MQTT_USER_NAME"]);
    conn_opts.set_password(global_data["MQTT_PASSWORD"]);
    conn_opts.set_clean_session(true);

    HHT_LOG(INFO) << "Connecting to the MQTT server..." << std::flush;
    try {
        mqtt::token_ptr conntok = client.connect(conn_opts);
        conntok->wait();
        HHT_LOG(INFO) << "OK";
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "\nERROR: Unable to connect to MQTT server: " << exc.what();
        return;
    }

    mqtt::token_ptr subtok = client.subscribe(global_data["MQTT_TOPIC"], 0);
    subtok->wait();

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    client.unsubscribe(global_data["MQTT_TOPIC"])->wait();
    client.disconnect()->wait();

    return;
}
*/