cmake_minimum_required(VERSION 3.2)

project(project_test)

SET(TEST_INSTALL_DIR ${PROJECT_TOP_DIR}/bin/test)


add_executable(test1 test1.cpp)
install(TARGETS test1 DESTINATION ${TEST_INSTALL_DIR})

add_executable(test2 test2.cpp)
install(TARGETS test2 DESTINATION ${TEST_INSTALL_DIR})

