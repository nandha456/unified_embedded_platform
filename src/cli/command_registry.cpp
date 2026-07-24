#include "command_registry.hpp"

#include <iostream>

void CommandRegistry::registryCommand(const std::string& name, CommandFactory factory){
    commands[name] = std::move(factory);
}

int CommandRegistry::executeCommand(const std::string& name){
    auto it = commands.find(name);
    if(it == commands.end()){
        std::cout<<"Unknown command : " << name << '\n';
        return 1;
    }
    auto command = it->second();
    
    return command->execute();
}