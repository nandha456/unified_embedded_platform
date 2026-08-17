#pragma once

#include <string>
#include <vector>

struct ProcessResult
{
    int exitCode;
    std::string standardOutput;
    std::string standardError;
};

class Process
{
public:
    static ProcessResult run(
        const std::string& command,
        const std::vector<std::string>& args = {}
    );
};



/*
this function is used to check if the required tools are installed and available in the system's PATH. It runs the following commands:

Process::run("arm-none-eabi-gcc", {"--version"});

Process::run("cmake", {"--version"});

Process::run("STM32_Programmer_CLI", {"--version"});

*/ 