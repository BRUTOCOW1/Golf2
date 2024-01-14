#ifndef GDBI_HPP
#define GDBI_HPP

#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>

using namespace std;


class GDBI {
    public:
        GDBI();

        void connect();

        void disconnect();

        bool query(std::string queryString);

        void select(std::string queryString);

        void insert(std::string queryString);

        const char* strToCharray(std::string q)
        {
            char* conn = new char[q.size() + 1];
            std::copy(q.begin(), q.end(), conn);
            conn[q.size()] = '\0';
            return conn;
        }


    private:

        string conn = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost;DATABASE=golf_db;UID=sa;PWD=golfPass1029@";

        SQLHENV hEnv;

        SQLHDBC hDbc;

        SQLCHAR* connectionString;

        SQLRETURN ret;

        SQLHSTMT hStmt;



};

#include "GDBI.cpp" 
#endif // GDBI_HPP
