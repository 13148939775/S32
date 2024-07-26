#include <iostream>
#include <sqlite_operator.h>

using namespace HHT;

int main()
{
    SqliteOperatorModel::Init("accountManagement.db");        //fill in ":memory:" if want to use memory mode
    SqliteOperatorModel userModel;

    std::string createTable = "CREATE TABLE COMPANY(" \
        "ID INT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL," \
        "AGE            INT     NOT NULL," \
        "ADDRESS        CHAR(50)," \
        "SALARY         REAL);";
    // 直接运行脚本
    SqliteOperator::GetClient()->Exec(createTable);

    SqliteOperatorCols c1;

    //插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
    std::string arr[]{"ID", "NAME", "AGE", "ADDRESS", "SALARY"};
    c1.AddInstance(arr, "acacb", 1, std::string("Name1"), 26, std::string("addr1"), 3023.21);
    userModel.Table("COMPANY").Insert(c1).Exec();

    c1.AddInstance(arr, "acacb", 2, std::string("Name2"), 27, std::string("addr2"), 3023.21);
    userModel.Table("COMPANY").Insert(c1).Exec();

    c1.AddInstance(arr, "acacb", 3, std::string("Name3"), 28, std::string("addr3"), 3023.21);
    userModel.Table("COMPANY").Insert(c1).Exec();

    SqliteOperatorInPars squery;
    squery.Add(0);
    squery.Add(25);

    // 带参数查询（参数检查特殊符号，防注入）
    SqliteOperatorRows userComs = userModel.Table("COMPANY").Select("ID,AGE,NAME,ADDRESS").Where("ID > ? and AGE > ?").FindAlls(squery);
    SqliteOperatorModel::OutStr(userComs);

    // 带参数更新数据（参数检查特殊符号，防注入）
    squery.Clear();
    squery.Add("Name4");
    squery.Add("addr4");
    userModel.Table("COMPANY").Update("NAME=?,ADDRESS=?").Where("ID = 2").Exec(squery);

    squery.Clear();
    squery.Add(0);
    squery.Add(25);
    // 带参数查询（参数检查特殊符号，防注入）
    userComs = userModel.Table("COMPANY").Select("ID,AGE,NAME,ADDRESS").Where("ID > ? and AGE > ?").FindAlls(squery);
    SqliteOperatorModel::OutStr(userComs);

    // 带参数删除数据（参数检查特殊符号，防注入）
    userModel.Table("COMPANY").Del().Where("ID = 2").Exec();

    // 带参数查询（参数检查特殊符号，防注入）
    squery.Clear();
    squery.Add(0);
    squery.Add(25);
    userComs = userModel.Table("COMPANY").Select("ID,AGE,NAME,ADDRESS").Where("ID > ? and AGE > ?").FindAlls(squery);
    SqliteOperatorModel::OutStr(userComs);
}