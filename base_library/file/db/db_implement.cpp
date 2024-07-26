/*
 * @author 008196
 * @for DB interface
 * @version 0.1
 * @date 2023-05
 *
 * @Copyrigh (c) HIPHI Co., LTD 2023
 *
 */

namespace HHT {
class DBIF::Impl {
public:
    bool Insert()
    { }

    bool Delete()
    { }

    void GetMatchedData(const int aParamValue)
    {
        // Bind the integer value provided to the first parameter of the SQL query
        query_.bind(":min_weight", aParamValue); // same as query_.bind(1, aParamValue);

        // Loop to execute the query step by step, to get one a row of results at a time
        while (query_.executeStep()) {
            return query_.getColumn(0);
        }

        // Reset the query to be able to use it again later
        query_.reset();
    }
}
}