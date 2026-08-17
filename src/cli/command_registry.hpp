#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "command.hpp"

class CommandRegistry {
public:
    using CommandFactory = std::function<std::unique_ptr<Command>()>;

    void registerCommand(const std::string& name, CommandFactory factory);
    int execute(const std::string& name);
    
//store the command name and its corresponding factory function in an unordered map
private:
    std::unordered_map<std::string, CommandFactory> commands;
};