//
// Created by kulichkoff on 28.03.2022.
//

#include "mysql_connector.h"

MySQLConnector::MySQLConnector() {
  try {
    driver_ = get_driver_instance();
    connection_ = driver_->connect(server_, username_, password_);
  } catch (sql::SQLException e) {
    std::cout << "Could not connect to server_. Error message: " << e.what() << std::endl;
    system("pause");
    exit(1);
  }
}

MySQLConnector::~MySQLConnector() {
  delete connection_;
//  delete statement_;
//  delete prepared_statement_;
}

void MySQLConnector::ConnectTo(const std::string &database_name) {
  connection_->setSchema(database_name);
}

sql::ResultSet *MySQLConnector::FindAllFrom(const std::string &table) {
  prepared_statement_ = connection_->prepareStatement("SELECT * FROM " + table);
  return prepared_statement_->executeQuery();
}
