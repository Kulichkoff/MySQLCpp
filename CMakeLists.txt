cmake_minimum_required(VERSION 3.21)
project(MySQLCpp)

set(CMAKE_CXX_STANDARD 20)

set(MYSQL_CONNECTOR_CPP_DIR /usr/local/include/connector-c++-8.0)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
include_directories(${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)
link_directories(${MYSQL_CONNECTOR_CPP_DIR}/lib64)

add_executable(MySQLCpp main.cpp mysql_connector/mysql_connector.cc mysql_connector/mysql_connector.h)
target_link_libraries(MySQLCpp mysqlcppconn)
target_compile_features(MySQLCpp PRIVATE cxx_range_for)
