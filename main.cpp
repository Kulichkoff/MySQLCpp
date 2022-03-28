#include <iostream>
#include "mysql_connector/mysql_connector.h"


int main() {
  auto *mysql = new MySQLConnector();

  mysql->ConnectTo("authentifications");
  auto *result = mysql->FindAllFrom("password");

  while (result->next())
    printf("Reading from table=(%d, %s, %s)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str());

  delete result;
  delete mysql;
  return 0;
}
