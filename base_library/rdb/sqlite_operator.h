/*
 * @author 008584
 * @for sqlite rdb operations' interface
 * @version 0.1
 * @date 2023-11-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SQLITE_OPERATOR_H
#define SQLITE_OPERATOR_H

#include <memory>
#include <string>
#include <mutex>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
#include <cstdarg>

#include <sqlite3.h>


namespace HHT {

enum class DataType {
    type_int = 0,
    type_str = 1,
    type_double = 2,
    type_null = 3
};

struct SqliteOperatorVal {
    DataType sType = DataType::type_str;
    int int_val = 0;
    std::string str_val;
    double d_val = 0;
    std::string null_val = "NULL";
};

class SqliteOperatorCols {
public:
    using iterator = std::map<std::string, SqliteOperatorVal>::iterator;
public:
    SqliteOperatorCols();
    ~SqliteOperatorCols();

    SqliteOperatorVal* Get(const std::string& key);

    void Add(const std::string& key,int val);
    void Add(const std::string& key, double val);
    void Add(const std::string& key, const std::string& val);
    void Add(const std::string& key, SqliteOperatorVal val);

    bool AddInstance(std::string key[], std::string typeSymbol, ...);

    iterator& Begin();
    iterator& End();

    void Clear();
    int Size();

private:
    std::map<std::string, SqliteOperatorVal> m_clos;
    iterator m_clos_it;
};

using SqliteOperatorRows = std::vector<SqliteOperatorCols>;

class SqliteOperator {
public:
    static void Init(const std::string& dbName);

    std::string m_dbName;

    SqliteOperatorCols Find(const std::string& sql);
    SqliteOperatorRows FindAlls(const std::string& sql);
    int Exec(const std::string& sql);

    static SqliteOperator* GetClient() {
        return &m_SqliteOperator;
    };

private:
    sqlite3* db = nullptr;
    std::mutex lock_mutex;

    SqliteOperator();
    ~SqliteOperator();

    void DealBakVal(sqlite3_stmt* pStmt,int index,SqliteOperatorVal &out_operator);

    static SqliteOperator m_SqliteOperator;
};

class SqliteOperatorInPars {
public:
    SqliteOperatorInPars();
    ~SqliteOperatorInPars();

    void Add(int par);
    void Add(const std::string& par);
    void Add(double par);
    int Size();
    std::string At(int index);

    void Clear();

    const std::string operator[](size_t pos) const
    {
        return m_squery[pos];
    };

    bool GetCheckPar() { return m_isCheck; };

    static bool CheckPare(std::string a);
private:
    std::vector<std::string> m_squery;
    bool m_isCheck = true;
    bool CheckPar(const std::string& a);
};

class SqliteOperatorModel {
public:
    SqliteOperatorModel(const std::string& sqlstr = "");
    SqliteOperatorModel(const std::string& sqlstr, const std::string& table);
    ~SqliteOperatorModel();

    static void OutStr(SqliteOperatorRows rows);
    static void OutStr(SqliteOperatorCols cols);
    static void Init(const std::string& dbName = "test.db") {                //If want to use memory mode, please fill in ":memory:"
        SqliteOperator::Init(dbName);
    };
    std::string ToSqlStr()
    {
        return sqlstr;
    };
    SqliteOperatorModel Table(const std::string& tableName);
    SqliteOperatorModel Select(const std::string& select = "*");
    SqliteOperatorModel Where(const std::string& swhere);
    SqliteOperatorModel Where(SqliteOperatorCols swhere,const std::string& checkWhere="");
    SqliteOperatorModel Where_or(SqliteOperatorCols swhere, const std::string& checkWhere = "");
    SqliteOperatorModel Limit(int slimit);
    SqliteOperatorModel Limit(const std::string& slimit);
    SqliteOperatorModel Update(const std::string& set);
    SqliteOperatorModel Update(SqliteOperatorCols swhere, const std::string& checkWhere = "");
    SqliteOperatorModel OrderEsc(const std::string& sortstr);
    SqliteOperatorModel OrderDesc(const std::string& sortstr);
    SqliteOperatorModel Pages(int page=1,int pagesize=10);
    SqliteOperatorModel Del();
    SqliteOperatorModel Sql(const std::string& sql);

    //(isCheckWhere=false,swhere 不在 checkWhere集合,反之在)
    SqliteOperatorModel Insert(SqliteOperatorCols swhere, std::string checkWhere = "",bool isCheckWhere = true);

    SqliteOperatorCols Find();
    SqliteOperatorRows FindAlls();

    SqliteOperatorCols Find(SqliteOperatorInPars pars);
    SqliteOperatorRows FindAlls(SqliteOperatorInPars pars);

    int Exec();
    int Exec(SqliteOperatorInPars pars);

private:
    std::string sqlstr;
    std::string m_tableName;

    std::string ToParCols(SqliteOperatorCols swhere, std::string checkWhere = "", std::string link = " and ");
    std::string GetValFromOperatorVal(SqliteOperatorVal val);
};

}

#endif /* SQLITE_OPERATOR_H */