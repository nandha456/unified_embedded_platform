#include "config.hpp"

#include <fstream>
#include <stdexcept>
#include <string>

ProjectConfig Config::load(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Could not open config file: " + path
        );
    }

    ProjectConfig config;

    std::string line;

    while (std::getline(file, line))
    {
        // Ignore empty lines
        if (line.empty())
            continue;

        // Find '='
        const auto pos = line.find('=');

        if (pos == std::string::npos)
            continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        // Remove spaces from key
        while (!key.empty() && key.back() == ' ')
            key.pop_back();

        // Remove spaces from beginning of value
        while (!value.empty() && value.front() == ' ')
            value.erase(value.begin());

        // Remove quotes
        if (value.size() >= 2 &&
            value.front() == '"' &&
            value.back() == '"')
        {
            value = value.substr(1, value.size() - 2);
        }

        if (key == "name")
            config.name = value;
        else if (key == "board")
            config.board = value;
        else if (key == "toolchain")
            config.toolchain = value;
        else if (key == "flasher")
            config.flasher = value;
        else if (key == "optimization")
            config.optimization = value;
    }

    return config;
}