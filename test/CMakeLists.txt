cmake_minimum_required(VERSION 3.2)

project(project_test)

SET(TEST_INSTALL_DIR ${PROJECT_TOP_DIR}/bin/test)
include(${PROJECT_TOP_DIR}/cmake/TestDepend.cmake)

FILE(GLOB TEST_SRC "${PROJECT_SOURCE_DIR}/*.cpp")
foreach(item IN LISTS TEST_SRC)
    get_filename_component(SRCNAME ${item} NAME_WE) #得到文件的名字，不带扩展名
    add_executable(${SRCNAME} ${item})
    target_link_libraries(${SRCNAME} doctest_with_main nanobench)
    install(TARGETS ${SRCNAME} DESTINATION ${TEST_INSTALL_DIR})
    message(STATUS "Test : ${SRCNAME} <- ${item}")
endforeach(item)
