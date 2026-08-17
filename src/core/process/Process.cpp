#include "Process.hpp"

#include <array>
#include <cstdio>
#include <sstream>
#include <sys/wait.h>

ProcessResult Process::run(
    const std::string& command,
    const std::vector<std::string>& args)
{
    std::string fullCommand = command;

    for (const auto& arg : args)
    {
        fullCommand += " ";
        fullCommand += arg;
    }

    fullCommand += " 2>&1";

    FILE* pipe = popen(fullCommand.c_str(), "r");

    if (!pipe)
    {
        return {
            -1,
            "",
            "Failed to start process"
        };
    }

    std::array<char, 256> buffer{};
    std::ostringstream output;

    while (fgets(buffer.data(), buffer.size(), pipe))
    {
        output << buffer.data();
    }

    int status = pclose(pipe);

    int exitCode = -1;

    if (WIFEXITED(status))
    {
        exitCode = WEXITSTATUS(status);
    }

    return {
        exitCode,
        output.str(),
        ""
    };
}