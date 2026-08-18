#include "run_command.hpp"

#include "../core/build/Builder.hpp"
#include "../core/flash/flash.hpp"

#include <iostream>

int RunCommand::execute()
{
    std::cout << "=== UnixTron Run ===\n\n";

    Builder builder;

    if (!builder.build())
    {
        std::cerr << "\nBuild failed. Run stopped.\n";
        return 1;
    }

    std::cout << "\n";

    Flasher flasher;

    if (!flasher.flash())
    {
        std::cerr << "\nFlash failed. Run stopped.\n";
        return 1;
    }

    std::cout << "\nRun successful.\n";

    return 0;
}