/*
 * @author 008196
 * @for DB interface
 * @incase of discotinue network
 * @version 0.1
 * @date 2023-05
 *
 * @Copyrigh (c) HIPHI Co., LTD 2023
 *
 */

#ifndef DB_INTERFACE_H
#define DB_INTERFACE_H

#include <memory>
#include <string>

#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>

namespace HHT {

class DBIF {
public:
    // Constructor
    DBIF(std::string& dbFile)
      : db_(dbFile),
        query_(db_, "SELECT * FROM test WHERE weight > :min_weight"),
        pImpl_(std::make_shared<Impl>(dbFile))
    { }

    virtual ~DBIF()
    { }

    bool Insert(bool InMemory = true)
    {
        pImpl_->Insert();
    }

    bool Delete()
    {
        pImpl_->Delete();
    }

    void GetMatchedData(const int aParamValue)
    {
        return pImpl_->GetMatchedData();
    }

private:
    SQLite::Database    db_;    ///< Database connection
    SQLite::Statement   query_; ///< Database prepared SQL query
    struct Impl;
    std::unique_ptr<Impl> pImpl_;
};

}

#endif /* DB_INTERFACE_H */
