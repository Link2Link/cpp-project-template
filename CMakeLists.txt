cmake_minimum_required(VERSION 3.16)

project(cpp-project-template)

set(CMAKE_CXX_STANDARD 17)
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")
elseif (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  /std:c++17")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++17 -O3")
endif (CMAKE_COMPILER_IS_GNUCXX)

    set(PROJECT_TOP_DIR ${PROJECT_SOURCE_DIR})
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/bin)

FILE(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
include_directories(${PROJECT_SOURCE_DIR}/include/CHEN)

add_executable(CHEN ${SRC})
install(TARGETS CHEN DESTINATION ${PROJECT_SOURCE_DIR}/bin) #安装到bin目录

option(TEST_OPTION "Test Option" ON)
if(${TEST_OPTION})
    add_definitions(-DTEST_OPTION)
    message(STATUS "Test Option ON")
    add_subdirectory(test)
else()
    message(STATUS "Test Option OFF")
endif()
