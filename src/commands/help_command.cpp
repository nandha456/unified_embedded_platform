#include "help_command.hpp"

#include <iostream>

int HelpCommand::execute()
{
    std::cout
        << "Available Commands\n\n"
        << "init\n"
        << "version\n"
        << "help\n"
        << "build\n"
        << "flash\n"
        << "run\n";

    return 0;
}