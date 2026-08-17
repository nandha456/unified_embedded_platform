#include "command_registry.hpp"
#include <iostream>
// Implementation of CommandRegistry methods
void CommandRegistry::registerCommand(const std::string& name, CommandFactory factory) {
    commands[name] = std::move(factory);
}
//check if the command exists in the registry and execute it, otherwise print an error message

int CommandRegistry::execute(const std::string& name) {
    auto it = commands.find(name);
    if (it == commands.end()) {
        std::cout << "Unknown command : " << name << '\n';
        return 1;
    }

    auto command = it->second();
    return command->execute();
}