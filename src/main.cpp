#include <iostream>

#include "cli/command_registry.hpp"

#include "commands/help_command.hpp"
#include "commands/init_command.hpp"
#include "commands/version_command.hpp"
#include "commands/build_command.hpp"
#include "commands/flasher_command.hpp"
#include "commands/run_command.hpp"

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

    registry.registerCommand(
        "build",
        []()
        {
            return std::make_unique<BuildCommand>();
        });

    registry.registerCommand(
        "flash",
        []()
        {
            return std::make_unique<FlasherCommand>();
        });

    registry.registerCommand(
        "run",
        []()
        {
            return std::make_unique<RunCommand>();
        }); 
    
        
    if (argc < 2)
    {
        registry.execute("help");
        return 0;
    }

    return registry.execute(argv[1]);
}