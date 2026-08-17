#include "version_command.hpp"

#include <iostream>

int VersionCommand::execute()
{
    std::cout
        << "UnixTron CLI\n"
        << "Version 0.0.1\n";

    return 0;
}