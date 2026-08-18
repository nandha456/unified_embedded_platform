#include "flash.hpp"

#include "../process/Process.hpp"

#include <iostream>
#include <vector>
#include <string>

bool Flasher::flash()
{
    std::cout << "=== UnixTron Flash ===\n";

    std::vector<std::string> args = {
        "-a", "0",
        "-s", "0x08000000:leave",
        "-D", "build/firmware.bin"
    };

    auto result = Process::run("dfu-util", args);

    if (result.exitCode != 0)
    {
        std::cerr << "      FAILED\n";
        std::cerr << result.standardOutput;
        return false;
    }

    std::cout << "      Flash successful\n";
    return true;
}