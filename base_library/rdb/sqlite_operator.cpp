/*
 * @author 008584
 * @for sqlite rdb operations' interface
 * @version 0.1
 * @date 2023-11-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sqlite_operator.h"
#include <memory>
#include "node_log.h"

namespace HHT {

SqliteOperator SqliteOperator::m_SqliteOperator;

SqliteOperator::SqliteOperator()
{ }

SqliteOperator::~SqliteOperator()
{
    sqlite3_close(db);
}

void SqliteOperator::DealBakVal(sqlite3_stmt* pStmt, int index, SqliteOperatorVal &out_operator)
{
    out_operator.d_val = 0;
    out_operator.int_val = 0;
    out_operator.str_val = "";

    int iType = sqlite3_column_type(pStmt, index);
    if (iType == SQLITE_INTEGER) {
        out_operator.int_val = sqlite3_column_int(pStmt, index);
        out_operator.sType = DataType::type_int;
    } else if (iType == SQLITE_FLOAT) {
        out_operator.d_val = sqlite3_column_double(pStmt, index);
        out_operator.sType = DataType::type_double;
    } else if (iType == SQLITE_TEXT) {
        const unsigned char* val = sqlite3_column_text(pStmt, index);
        out_operator.str_val = std::string((char*)val);
        out_operator.sType = DataType::type_str;
    } else if (iType == SQLITE_NULL) {
        out_operator.null_val = "NULL";
        out_operator.sType = DataType::type_null;
    }
}

SqliteOperatorCols SqliteOperator::Find(const std::string& sql)
{
    SqliteOperatorCols tmp_map;
    SqliteOperatorVal tmpval;
    sqlite3_stmt* pStmt;
    int r = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        sql.size(),
        &pStmt,
        nullptr);

    if (r != SQLITE_OK) {
        perror("sqlite3_prepare_v2 error:");
        return tmp_map;
    }

    int i;
    r = sqlite3_step(pStmt);
    if (r == SQLITE_DONE) {
        printf("o la\n");
    } else if (r == SQLITE_ROW) {
        int cNum = sqlite3_column_count(pStmt);
        for (i = 0; i < cNum; i++) {
            DealBakVal(pStmt,i, tmpval);
            const char* p = sqlite3_column_name(pStmt, i);
            tmp_map.Add(std::string(p), tmpval);
        }
    }

    sqlite3_finalize(pStmt);
    pStmt = nullptr;

    return tmp_map;
}

void SqliteOperator::Init(const std::string& dbName)
{
    m_SqliteOperator.m_dbName = dbName;

    int rc = sqlite3_open(m_SqliteOperator.m_dbName.c_str(), &m_SqliteOperator.db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_SqliteOperator.db));
        exit(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
}

SqliteOperatorRows SqliteOperator::FindAlls(const std::string& sql)
{
    SqliteOperatorRows tmp_map_list;
    SqliteOperatorCols tmp_map;

    SqliteOperatorVal tmpval;

    sqlite3_stmt* pStmt;
    int r = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        sql.size(),
        &pStmt,
        nullptr);

    if (r != SQLITE_OK) {
        perror("sqlite3_prepare_v2 error:");
        return tmp_map_list;
    }

    int i;
    while (1) {
        r = sqlite3_step(pStmt);
        if (r == SQLITE_DONE) {
            break;
        } else if (r == SQLITE_ROW) {
            int cNum = sqlite3_column_count(pStmt);
            for (i = 0; i < cNum; i++) {
                DealBakVal(pStmt, i, tmpval);
                const char* p = sqlite3_column_name(pStmt, i);
                tmp_map.Add(std::string(p), tmpval);
            }
            tmp_map_list.push_back(tmp_map);
        }
    }
    sqlite3_finalize(pStmt);
    pStmt = nullptr;
    return tmp_map_list;
}


int SqliteOperator::Exec(const std::string& sql)
{
    std::lock_guard<std::mutex> lockGuard(lock_mutex);

    int bak = 0;
    sqlite3_stmt* stmt = nullptr;

    int result = sqlite3_prepare_v2(db, sql.c_str(), sql.size(), &stmt, nullptr);
    if (result == SQLITE_OK) {
        //执行该语句
        sqlite3_step(stmt);
        bak = 1;
    }
    else {
        bak = -1;
    }

    sqlite3_finalize(stmt);
    stmt = nullptr;
    return bak;
}

std::string SqliteOperatorModel::ToParCols(SqliteOperatorCols swhere, std::string checkWhere, std::string link)
{
    if (checkWhere.size() > 0) {
        checkWhere = "," + checkWhere + ",";
    }

    std::string str_w = "";
    SqliteOperatorCols::iterator col_it;
    bool isfirst = true;
    if ((int)this->sqlstr.find(" where ") > 0) {
        isfirst = false;
    }
    for (col_it = swhere.Begin(); col_it != swhere.End(); col_it++) {
        if (checkWhere.size() > 0) {
            if ((int)checkWhere.find(col_it->first + ",") <= 0) {
                continue;
            }
        }
        if (isfirst) {
            isfirst = false;
            str_w += col_it->first + " = ";
        } else {
            str_w += link + col_it->first + " = ";
        }
        str_w += GetValFromOperatorVal(col_it->second);
    }
    return str_w;
}

std::string SqliteOperatorModel::GetValFromOperatorVal(SqliteOperatorVal val)
{
    std::string str_w = "";
    if (val.sType == DataType::type_str) {
        str_w = "'" + val.str_val + "'";
    } else if (val.sType == DataType::type_int) {
        str_w = std::to_string(val.int_val);
    } else if (val.sType == DataType::type_double) {
        str_w = std::to_string(val.d_val);
    } else if (val.sType == DataType::type_null) {
        str_w = val.null_val;
    }
    return str_w;
}

SqliteOperatorModel::SqliteOperatorModel(const std::string& sqlstr)
{
    this->sqlstr = sqlstr;
}

SqliteOperatorModel::SqliteOperatorModel(const std::string& sqlstr, const std::string& table)
{
    this->sqlstr = sqlstr;
    this->m_tableName = table;
}

SqliteOperatorModel::~SqliteOperatorModel()
{
    this->sqlstr = "";
}

SqliteOperatorModel SqliteOperatorModel::Table(const std::string& tableName)
{
    this->m_tableName = tableName;
    return SqliteOperatorModel(*this);
}
SqliteOperatorModel SqliteOperatorModel::Select(const std::string& select)
{
    this->sqlstr = "SELECT " + select + " from `" + this->m_tableName + "`";
    return SqliteOperatorModel(*this);
}
SqliteOperatorModel SqliteOperatorModel::Where(const std::string& swhere)
{
    if ((int)this->sqlstr.find(" where ") < 0) {
        this->sqlstr += " where ";
    }
    this->sqlstr += " " + swhere;
    return SqliteOperatorModel(*this);
}

SqliteOperatorModel SqliteOperatorModel::Where(SqliteOperatorCols swhere, const std::string& checkWhere)
{
    return this->Where(ToParCols(swhere, checkWhere," and "));
}

SqliteOperatorModel SqliteOperatorModel::Where_or(SqliteOperatorCols swhere, const std::string& checkWhere)
{
    return this->Where(ToParCols(swhere, checkWhere, " or "));
}

SqliteOperatorModel SqliteOperatorModel::Limit(int slimit){
    this->sqlstr += " limit " + std::to_string(slimit);
    return SqliteOperatorModel(*this);
};

SqliteOperatorModel SqliteOperatorModel::Limit(const std::string& sLimit){
    this->sqlstr += " limit " + sLimit;
    return SqliteOperatorModel(*this);
};

SqliteOperatorCols SqliteOperatorModel::Find()
{
    this->sqlstr += " limit 1";
    return SqliteOperator::GetClient()->Find(this->sqlstr);
}
SqliteOperatorRows SqliteOperatorModel::FindAlls()
{
    return SqliteOperator::GetClient()->FindAlls(this->sqlstr);
}

SqliteOperatorModel SqliteOperatorModel::Update(const std::string& set)
{
    this->sqlstr = "update `" + this->m_tableName + "` set " + set;
    return SqliteOperatorModel(*this);
}

SqliteOperatorModel SqliteOperatorModel::Update(SqliteOperatorCols swhere, const std::string& checkWhere)
{
    return this->Update(ToParCols(swhere, checkWhere, " , "));
}

SqliteOperatorModel SqliteOperatorModel::OrderEsc(const std::string& sortstr)
{
    this->sqlstr += " order by " + sortstr;
    return SqliteOperatorModel(*this);
}

SqliteOperatorModel SqliteOperatorModel::OrderDesc(const std::string& sortstr)
{
    this->sqlstr += " order by " + sortstr + " desc";
    return SqliteOperatorModel(*this);
}

SqliteOperatorModel SqliteOperatorModel::Pages(int page,int pagesize)
{
    int beg = (page - 1) * pagesize;
    this->sqlstr += " limit " + std::to_string(beg) + "," + std::to_string(pagesize);
    return SqliteOperatorModel(*this);
}

SqliteOperatorModel SqliteOperatorModel::Del()
{
    this->sqlstr = "DELETE FROM `" + m_tableName + "` ";
    return SqliteOperatorModel(*this);
}

SqliteOperatorModel SqliteOperatorModel::Sql(const std::string& sql)
{
    this->sqlstr = sql;
    return SqliteOperatorModel(*this);
}

SqliteOperatorModel SqliteOperatorModel::Insert(SqliteOperatorCols swhere, std::string checkWhere, bool isCheckWhere)
{
    if (checkWhere.size() > 0) {
        checkWhere = "," + checkWhere + ",";
    }
    std::string str_key = "";
    std::string str_val = "";
    SqliteOperatorCols::iterator col_it;
    bool isfirst = true;
    if ((int)this->sqlstr.find(" where ") > 0) {
        isfirst = false;
    }
    for (col_it = swhere.Begin(); col_it != swhere.End(); col_it++) {
        if (checkWhere.size() > 0) {
            int findex = checkWhere.find(col_it->first + ",");
            if (isCheckWhere) {
                if (findex <= 0) {
                    continue;
                }
            } else {
                if (findex > 0) {
                    continue;
                }
            }
        }
        if (isfirst) {
            isfirst = false;
        } else {
            str_key += ",";
            str_val += ",";
        }
        str_key += "`" + col_it->first + "`";
        str_val += GetValFromOperatorVal(col_it->second);
    }
    this->sqlstr = "INSERT INTO " + this->m_tableName + " (" + str_key + ") VALUES ("+ str_val + ")";
    return SqliteOperatorModel(*this);
}

SqliteOperatorCols SqliteOperatorModel::Find(SqliteOperatorInPars pars)
{
    if (!pars.GetCheckPar()) {
        return SqliteOperatorCols();
    }
    std::string tmpsql = this->sqlstr;

    int find_index = 0;
    int qlien = pars.Size();
    for (int i = 0; i < qlien; i++) {
        find_index = tmpsql.find('?', find_index);
        tmpsql.replace(find_index,1, pars[i] ,0, pars[i].size());
    }

    return SqliteOperator::GetClient()->Find(tmpsql);
}

SqliteOperatorRows SqliteOperatorModel::FindAlls(SqliteOperatorInPars pars)
{
    if (!pars.GetCheckPar()) {
        return SqliteOperatorRows();
    }

    std::string tmpsql = this->sqlstr;

    int find_index = 0;
    int qlien = pars.Size();
    for (int i = 0; i < qlien; i++) {
        find_index = tmpsql.find('?', find_index);
        if (find_index > 0) {
            tmpsql.replace(find_index,1, pars[i] ,0, pars[i].size());
        }
    }

    return SqliteOperator::GetClient()->FindAlls(tmpsql);
}

int SqliteOperatorModel::Exec()
{
    return SqliteOperator::GetClient()->Exec(this->sqlstr);
}

int SqliteOperatorModel::Exec(SqliteOperatorInPars pars)
{
    if (!pars.GetCheckPar()) {
        return -2;
    }

    std::string tmpsql = this->sqlstr;

    int find_index = 0;
    int qlien = pars.Size();
    for (int i = 0; i < qlien; i++) {
        find_index = tmpsql.find('?', find_index);
        if (find_index > 0) {
            tmpsql.replace(find_index,1, pars[i] ,0, pars[i].size());
        } else {
            break;
        }
    }

    return SqliteOperator::GetClient()->Exec(tmpsql);
}

void SqliteOperatorModel::OutStr(SqliteOperatorRows rows)
{
    SqliteOperatorRows::iterator it;
    for (it = rows.begin(); it != rows.end(); it++) {
        SqliteOperatorCols tmp = *it;
        OutStr(tmp);
    }
}

void SqliteOperatorModel::OutStr(SqliteOperatorCols cols)
{
    std::cout << "outStr: " << std::endl;
    SqliteOperatorCols::iterator col_it;
    for (col_it = cols.Begin(); col_it != cols.End(); col_it++) {
        std::cout << col_it->first << ":";
        SqliteOperatorVal tmp_val = col_it->second;
        if (tmp_val.sType == DataType::type_int) {
            std::cout << tmp_val.int_val << ",";
        } else if (tmp_val.sType == DataType::type_double) {
            std::cout << tmp_val.d_val << ",";
        } else if (tmp_val.sType == DataType::type_str) {
            std::cout << tmp_val.str_val << ",";
        }
    }
}

SqliteOperatorInPars::SqliteOperatorInPars()
{ }

SqliteOperatorInPars::~SqliteOperatorInPars()
{
    m_squery.clear();
}

void SqliteOperatorInPars::Add(int par)
{
    m_squery.push_back(std::to_string(par));
}

void SqliteOperatorInPars::Add(const std::string& par)
{
    CheckPar(par);
    m_squery.push_back("'" + par + "'");
}

void SqliteOperatorInPars::Add(double par)
{
    m_squery.push_back(std::to_string(par));
}

int SqliteOperatorInPars::Size()
{
    return m_squery.size();
}

std::string SqliteOperatorInPars::At(int index)
{
    if (index >= Size()) {
        return "";
    }
    return m_squery[index];
}

void SqliteOperatorInPars::Clear()
{
    m_squery.clear();
    m_isCheck = true;
}

bool SqliteOperatorInPars::CheckPare(std::string a)
{
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    static const std::string key[] = { "and ","exec ","insert ","select ","delete ","update ","count ","*","%","chr","mid" ,"master ","truncate ","char ","declare ",";","or ","-","+",",","drop ","\'"};
    for (int i = 0; i < 22; i++) {
        if (a.find(key[i]) != std::string::npos) {
            return false;
        }
    }
    return true;
}

bool SqliteOperatorInPars::CheckPar(const std::string& a)
{
    m_isCheck = CheckPare(a);
    return m_isCheck;
}

SqliteOperatorCols::SqliteOperatorCols()
{ }

SqliteOperatorCols::~SqliteOperatorCols()
{
    m_clos.clear();
}

SqliteOperatorVal* SqliteOperatorCols::Get(const std::string& key)
{
    return &m_clos[key];
}

bool SqliteOperatorCols::AddInstance(std::string key[], std::string typeSymbol, ...)
{
    va_list valueList;
    va_start(valueList, typeSymbol);

    int count = typeSymbol.length();

    for (int i = 0; i < count; i++) {
        char ch = typeSymbol[i];
        int value_int;
        double value_double;
        std::string value_string;

        switch (ch)
        {
        case 'a':
            value_int = va_arg(valueList, int);
            Add(key[i], value_int);
            break;
        case 'b':
            value_double = va_arg(valueList, double);
            Add(key[i], value_double);
            break;
        case 'c':
            value_string = va_arg(valueList, std::string);
            Add(key[i], value_string);
            break;
        default:
            break;
        }
    }

    return true;
}

void SqliteOperatorCols::Add(const std::string& key, int val)
{
    // if (!SqliteOperatorInPars::CheckPare(key)) {
    //     return;
    // }
    
    SqliteOperatorVal tval;
    tval.sType = DataType::type_int;
    tval.int_val = val;
    m_clos[key] = tval;
}

void SqliteOperatorCols::Add(const std::string& key, double val)
{
    // if (!SqliteOperatorInPars::CheckPare(key)) {
    //     return;
    // }
    SqliteOperatorVal tval;
    tval.sType = DataType::type_double;
    tval.d_val = val;
    m_clos[key] = tval;
}

void SqliteOperatorCols::Add(const std::string& key, const std::string& val)
{
    // if (SqliteOperatorInPars::CheckPare(val) && SqliteOperatorInPars::CheckPare(key)) {
    //     SqliteOperatorVal tval;
    //     tval.sType = DataType::type_str;
    //     tval.str_val = val;
    //     m_clos[key] = tval;
    // }

    SqliteOperatorVal tval;
    tval.sType = DataType::type_str;
    tval.str_val = val;
    m_clos[key] = tval;
}

void SqliteOperatorCols::Add(const std::string& key, SqliteOperatorVal val)
{
    // if (SqliteOperatorInPars::CheckPare(key) && SqliteOperatorInPars::CheckPare(val.str_val)) {
    //     m_clos[key] = val;
    // }
    m_clos[key] = val;
}

SqliteOperatorCols::iterator& SqliteOperatorCols::Begin()
{
    m_clos_it = m_clos.begin();
    return m_clos_it;
}

SqliteOperatorCols::iterator& SqliteOperatorCols::End()
{
    m_clos_it = m_clos.end();
    return m_clos_it;
}

void SqliteOperatorCols::Clear()
{
    m_clos.clear();
}
int SqliteOperatorCols::Size()
{
    return m_clos.size();
}

}