#pragma once

#include "../cli/command.hpp"

class InitCommand : public Command
{
public:
    int execute() override;
};