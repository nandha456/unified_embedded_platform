#include "flash.hpp"

#include "../config/config.hpp"
#include "../process/Process.hpp"

#include <iostream>

bool Flasher::flash()
{
    auto config = Config::load("unixtron.toml");

    std::cout << "=== UnixTron Flash ===\n";
    std::cout << "Board : " << config.board << "\n\n";

    auto result = Process::run(
        "STM32_Programmer_CLI",
        {
            "-c",
            "port=SWD",
            "-w",
            "build/firmware.bin",
            "0x08000000",
            "-v",
            "-rst"
        }
    );

    std::cout << result.standardOutput;

    if (result.exitCode != 0)
    {
        std::cerr << result.standardError;
        std::cerr << "\nFlash failed.\n";
        return false;
    }

    std::cout << "\nFlash successful.\n";

    return true;
}