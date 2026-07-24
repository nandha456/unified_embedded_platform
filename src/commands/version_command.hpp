#pragma once

#include "../cli/command.hpp"

class VersionCommand : public Command
{
public:
    int execute() override;
};