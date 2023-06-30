cmake_minimum_required(VERSION 3.2)

project(cpp-project-template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(PROJECT_TOP_DIR ${PROJECT_SOURCE_DIR})

FILE(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
include_directories(${PROJECT_SOURCE_DIR}/include/CHEN)

add_executable(CHEN ${SRC})
install(TARGETS CHEN DESTINATION ${PROJECT_SOURCE_DIR}/bin) #安装到bin目录


add_subdirectory(test)