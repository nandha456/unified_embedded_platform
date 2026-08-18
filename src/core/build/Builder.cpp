#include "Builder.hpp"

#include "../config/config.hpp"
#include "../process/Process.hpp"

#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

bool Builder::build()
{
    auto config = Config::load("unixtron.toml");

    std::cout << "=== UnixTron Build ===\n";
    std::cout << "Project : " << config.name << "\n";
    std::cout << "Board   : " << config.board << "\n\n";

    fs::create_directories("build");

    std::cout << "[1/3] Compiling main.c...\n";

    auto mainResult = Process::run(
        config.toolchain,
        {
            "-mcpu=cortex-m4",
            "-mthumb",
            "-ffreestanding",
            "-c",
            "src/main.c",
            "-o",
            "build/main.o"
        }
    );

    if (mainResult.exitCode != 0)
    {
        std::cerr << mainResult.standardError;
        return false;
    }

    std::cout << "      OK\n";

    std::cout << "[2/3] Compiling startup.c...\n";

    auto startupResult = Process::run(
        config.toolchain,
        {
            "-mcpu=cortex-m4",
            "-mthumb",
            "-ffreestanding",
            "-c",
            "src/startup.c",
            "-o",
            "build/startup.o"
        }
    );

    if (startupResult.exitCode != 0)
    {
        std::cerr <<"       FAILED\n";
        std::cerr << startupResult.standardOutput;
        return false;
    }

    std::cout << "      OK\n";

    std::cout << "[3/3] Linking firmware...\n";

    auto linkResult = Process::run(
        config.toolchain,
        {
            "-mcpu=cortex-m4",
            "-mthumb",
            "-Tsrc/Linker.ld",
            "-nostdlib",
            "build/startup.o",
            "build/main.o",
            "-o",
            "build/firmware.elf"
        }
    );

    if (linkResult.exitCode != 0)
    {
        std::cerr << linkResult.standardOutput;
        return false;
    }

    std::cout << "      ELF created\n";

    auto objcopyResult = Process::run(
        "arm-none-eabi-objcopy",
        {
            "-O",
            "binary",
            "build/firmware.elf",
            "build/firmware.bin"
        }
    );

    if (objcopyResult.exitCode != 0)
    {
        std::cerr << objcopyResult.standardOutput;
        return false;
    }

    std::cout << "      BIN created\n\n";

    std::cout << "Build successful.\n";

    return true;
}