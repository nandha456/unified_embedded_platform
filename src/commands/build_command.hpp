#pragma once

#include "../cli/command.hpp"

class BuildCommand : public Command
{
public:
    int execute() override;
};