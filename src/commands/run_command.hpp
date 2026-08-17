#pragma once

#include "../cli/command.hpp"

class RunCommand : public Command
{
public:
    int execute() override;
};