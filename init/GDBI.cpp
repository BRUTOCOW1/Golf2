#include "GDBI.hpp"



GDBI::GDBI()
{
    connect();
    disconnect();
}

void GDBI::connect() {
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

    // Initialize connection handle
    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

    // Connection parameters
    connectionString = (SQLCHAR*)strToCharray(conn);

    // Connect to the database
    ret = SQLDriverConnect(hDbc, NULL, connectionString, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        SQLCHAR sqlState[6], message[SQL_MAX_MESSAGE_LENGTH];
        SQLINTEGER nativeError;
        SQLSMALLINT length;

        SQLGetDiagRec(SQL_HANDLE_DBC, hDbc, 1, sqlState, &nativeError, message, SQL_MAX_MESSAGE_LENGTH, &length);

        std::cerr << "Connection failed. SQLSTATE: " << sqlState << ", Native error: " << nativeError << ", Message: " << message << std::endl;
    } else {
        std::cout << "Connected to the database successfully!" << std::endl;
    }

}

void GDBI::disconnect()
{
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
}


bool GDBI::query(std::string queryString)
{
    
    SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

    SQLCHAR* query = (SQLCHAR*)strToCharray(queryString);
    std::cout << "Executing query: " << query << std::endl;

    ret = SQLExecDirect(hStmt, query, SQL_NTS);

    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        SQLCHAR sqlState[6], message[SQL_MAX_MESSAGE_LENGTH];
        SQLINTEGER nativeError;
        SQLSMALLINT length;

        SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, 1, sqlState, &nativeError, message, SQL_MAX_MESSAGE_LENGTH, &length);

        std::cerr << "Query execution failed. SQLSTATE: " << sqlState << ", Native error: " << nativeError << ", Message: " << message << std::endl;
        return false;
    } else {
        // Process results here
        // Fetch and print data, etc.

        std::cout << "Query executed successfully!" << std::endl;
        
    }
    return true;
}

void GDBI::select(std::string queryString)
{
         if (!query(queryString)) return;
        SQLINTEGER id;
        SQLINTEGER froggy;
        
        while (SQLFetch(hStmt) == SQL_SUCCESS) {
            // Retrieve column values
            SQLGetData(hStmt, 1, SQL_C_SLONG, &id, 0, NULL);
            SQLGetData(hStmt, 2, SQL_C_SLONG, &froggy, 0, NULL);

            // Print the retrieved values
            std::cout << "ID: " << id << ", Froggy: " << froggy << std::endl;
        }

}

void GDBI::insert(std::string queryString)
{
    if (!query(queryString)) return;
    std::cout << "Insertion Successful" <<std::endl;
}