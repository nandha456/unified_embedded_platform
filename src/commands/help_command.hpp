#pragma once

#include "../cli/command.hpp"

class HelpCommand : public Command
{
public:
    int execute() override;
};