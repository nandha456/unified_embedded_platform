cmake_minimum_required(VERSION 3.20)

project(
    UNIXTRON                                            #project name
    VERSION 0.1.0                                       #project version
    DESCRIPTION "Unified Embedded Development Platform" 
    LANGUAGES CXX #c++ only
    )

set(CMAKE_CXX_STANDARD 20)                              #-std=c++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unixtron

    src/main.cpp

    src/cli/command_registry.cpp

    src/commands/build_command.cpp
    src/commands/flasher_command.cpp
    src/commands/help_command.cpp
    src/commands/init_command.cpp
    src/commands/run_command.cpp
    src/commands/version_command.cpp

    src/core/build/Builder.cpp
    src/core/config/config.cpp
    src/core/process/Process.cpp
    src/core/project/ProjectGenerator.cpp
    src/core/flash/flash.cpp
)

target_include_directories(unixtron PRIVATE
    src
)