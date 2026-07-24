cmake_minimum_required(VERSION 3.20)

project(
    UNIXTRON
    VERSION 0.0.1
    DESCRIPTION "Unified Embedded Development Platform" 
    LANGUAGES CXX #c++ only
    )

set(CMAKE_CXX_STANDARD 20)#-std=c++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    unixtron
    src/main.cpp
)