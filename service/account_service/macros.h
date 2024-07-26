/*
 * @author 008584
 * @for account_service
 * @version 1.0
 * @date 2023-11-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MACROS_H
#define MACROS_H

#include <iostream>

constexpr int ALIVE_INTERVAL = 20;

/*
GENDER--性别(1-男性, 2-女性)
IDENTITY--身份(1-车主用户, 2-授权用户)
OWNER_FLAG--特殊标识(0-非车主, 1-普通车主, 2-创始车主)
VALET_MODE--代客模式(1-开启, 2-关闭)
ACCOUNT_STATUS--账号状态(1-可用, 2-禁用)
*/
const std::string CREATE_ACCOUNT_BASE_TABLE = "CREATE TABLE ACCOUNT_BASE(" \
    "ID INT PRIMARY KEY     NOT NULL," \
    "PHONE          VARCHAR(20)," \
    "NAME           VARCHAR(20)," \
    "HEAD           VARCHAR(10000000000)," \
    "NICKNAME       VARCHAR(50)," \
    "GENDER         INT," \
    "CITY           VARCHAR(20)," \
    "TRADE          VARCHAR(20)," \
    "BIRTH          VARCHAR(50)," \
    "CAR_OWNED      VARCHAR(20)," \
    "IDENTITY       INT," \
    "OWNER_FLAG     INT," \
    "PIN_CODE       VARCHAR(20)," \
    "VALET_MODE     INT," \
    "FACE_ID        VARCHAR(20)," \
    "NFC_KEY        VARCHAR(20)," \
    "PHYSICAL_KEY   VARCHAR(20)," \
    "MOBILE_KEY     VARCHAR(20)," \
    "ACCOUNT_STATUS INT);";

/*
REMOTE_CONTROL--远控权限(1-开启, 2-关闭)
LOCATE--定位权限(1-开启, 2-关闭)
ALBUM--相册权限(1-开启, 2-关闭)
*/
const std::string CREATE_ACCOUNT_AUTHORIZE_TABLE = "CREATE TABLE ACCOUNT_AUTHORIZE(" \
    "ID INT PRIMARY KEY NOT NULL," \
    "REMOTE_CONTROL INT," \
    "LOCATE         INT," \
    "ALBUM          INT," \
    "AUTH_START     INT," \
    "AUTH_END       INT);";

const std::string CREATE_ACCOUNT_VEHICLE_CONTROL_TABLE = "CREATE TABLE ACCOUNT_VEHICLE_CONTROL(" \
    "ID INT PRIMARY KEY NOT NULL," \
    ");";

std::string ACCOUNT_BASE_ITEMS[]{"ID", "PHONE", "NAME", "HEAD", "NICKNAME", "GENDER", "CITY", \
"TRADE", "BIRTH", "CAR_OWNED", "IDENTITY", "OWNER_FLAG", "PIN_CODE", "VALET_MODE", "FACE_ID", \
"NFC_KEY", "PHYSICAL_KEY", "MOBILE_KEY", "ACCOUNT_STATUS"};
std::string ACCOUNT_BASE_DATA_TYPE = "accccaccccaacacccca";

std::string ACCOUNT_AUTHORIZE_ITEMS[]{"ID", "REMOTE_CONTROL", "LOCATE", "ALBUM", "AUTH_START", "AUTH_END"};
std::string ACCOUNT_AUTHORIZE_DATA_TYPE = "aaaaaa";

#endif /* MACROS_H */