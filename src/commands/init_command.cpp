#include "init_command.hpp"
#include "../core/project/ProjectGenerator.hpp"

#include <iostream>

int InitCommand::execute()
{
    ProjectGenerator generator;

    if(generator.createProject("blink"))
        return 0;

    return 1;
}