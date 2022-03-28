//
// Created by kulichkoff on 28.03.2022.
//

#ifndef MYSQLCPP_MYSQL_CONNECTOR_H_
#define MYSQLCPP_MYSQL_CONNECTOR_H_


#include <string>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class MySQLConnector {
private:
  std::string server_ = "tcp://localhost:3306";
  std::string username_ = "kulichkoff";
  std::string password_ = "PASSWORD";

  sql::Driver *driver_;
  sql::Connection *connection_;
  sql::Statement *statement_ = {};
  sql::PreparedStatement *prepared_statement_ = {};

public:
  MySQLConnector();
  ~MySQLConnector();

  void ConnectTo(const std::string &database_name);
  sql::ResultSet *FindAllFrom(const std::string &table);
};


#endif //MYSQLCPP_MYSQL_CONNECTOR_H_
