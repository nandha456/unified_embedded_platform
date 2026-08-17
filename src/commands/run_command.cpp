#include "run_command.hpp"

#include "../core/build/Builder.hpp"
#include "../core/flash/flash.hpp"

#include <iostream>

int RunCommand::execute()
{
    Builder builder;

    if (!builder.build())
    {
        std::cerr << "Build failed. Flash aborted.\n";
        return 1;
    }

    Flasher flasher;

    if (!flasher.flash())
    {
        return 1;
    }

    std::cout << "\nUnixTron: firmware running.\n";

    return 0;
}