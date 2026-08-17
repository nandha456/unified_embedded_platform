#pragma once

#include <string>

struct ProjectConfig
{
    std::string name;
    std::string board;
    std::string toolchain;
    std::string flasher;
    std::string optimization;
};

class Config
{
public:
    static ProjectConfig load(const std::string& path);
};