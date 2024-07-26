#include <gtest/gtest.h>
#include <iostream>
#include <sqlite_operator.h>

using namespace HHT;

TEST(SqliteOperator, CRUD)
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

    // 添加数据
    SqliteOperatorCols c1;

    std::string arr[]{"ID", "NAME", "AGE", "ADDRESS", "SALARY"};
    c1.AddInstance(arr, "acacb", 1, std::string("Name1"), 26, std::string("addr1"), 3023.21);
    userModel.Table("COMPANY").Insert(c1).Exec();

    c1.AddInstance(arr, "acacb", 2, std::string("Name2"), 27, std::string("addr2"), 3023.21);
    userModel.Table("COMPANY").Insert(c1).Exec();

    c1.AddInstance(arr, "acacb", 3, std::string("Name3"), 28, std::string("addr3"), 3023.21);
    userModel.Table("COMPANY").Insert(c1).Exec();

    SqliteOperatorInPars squery;
    squery.Add(1);
    squery.Add(23);

    // 带参数查询（参数检查特殊符号，防注入）
    SqliteOperatorRows userComs = userModel.Table("COMPANY").Select("ID,AGE,NAME").Where("ID > ? and AGE > ?").FindAlls(squery);
    SqliteOperatorModel::OutStr(userComs);

    squery.Clear();
    squery.Add("name3");
    squery.Add("addr3");


    // 带参数更新数据（参数检查特殊符号，防注入）
    userModel.Table("COMPANY").Update("NAME=?,ADDRESS=?").Where("ID = 2").Exec(squery);

    // 只使用 object userComs 里面的 ID 一项来查询
    userComs = userModel.Table("COMPANY").Select().Where(userComs[0],"ID").FindAlls();
    SqliteOperatorModel::OutStr(userComs);

    userComs[0].Get("ADDRESS")->str_val = "addr4----";
    userModel.Table("COMPANY").Update(userComs[0],"ADDRESS").Where("ID = 2").Exec();

    userComs = userModel.Table("COMPANY").Select().Where(userComs[0], "ID").FindAlls();
    SqliteOperatorModel::OutStr(userComs);

    userComs = userModel.Table("COMPANY").Select().FindAlls();
    SqliteOperatorModel::OutStr(userComs);

    SqliteOperatorCols maxId = userModel.Table("COMPANY").Select("max(ID) as maxid").Find();
    SqliteOperatorModel::OutStr(maxId);
}


//get条数
TEST(SqliteOperator, entryNums)
{
    SqliteOperatorModel userModel;

    SqliteOperatorInPars squery;
    squery.Add(1);
    squery.Add(23);

    // 带参数查询（参数检查特殊符号，防注入）
    SqliteOperatorRows userComs = userModel.Table("COMPANY").Select("ID,AGE,NAME").Where("ID > ? and AGE > ?").FindAlls(squery);
    SqliteOperatorModel::OutStr(userComs);

    EXPECT_EQ(userComs.size(), 2);
}