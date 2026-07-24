#include <iostream>

#include "cli/command_registry.hpp"

#include "commands/help_command.hpp"
#include "commands/init_command.hpp"
#include "commands/version_command.hpp"

int main(int argc, char* argv[])
{
    CommandRegistry registry;

    registry.registerCommand(
        "version",
        []()
        {
            return std::make_unique<VersionCommand>();
        });

    registry.registerCommand(
        "help",
        []()
        {
            return std::make_unique<HelpCommand>();
        });

    registry.registerCommand(
        "init",
        []()
        {
            return std::make_unique<InitCommand>();
        });

    if (argc < 2)
    {
        registry.execute("help");
        return 0;
    }

    return registry.execute(argv[1]);
}