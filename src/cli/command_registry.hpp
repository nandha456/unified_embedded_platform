#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "command.hpp"

class CommandRegistry {
    public:
        using CommandFactory = std::function<std::unique_ptr<Command>()>;

        void registryCommand(const std:: string& name, CommandFactory factory);

        int executeCommand(const std::string& name);

    private:
        std::unordered_map<std::string, CommandFactory> commands;
}