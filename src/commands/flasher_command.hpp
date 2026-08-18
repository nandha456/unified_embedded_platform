#pragma once

#include "../cli/command.hpp"

class FlasherCommand : public Command
{
public:
    int execute() override;
};