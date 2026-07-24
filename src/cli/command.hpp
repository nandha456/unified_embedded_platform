#pragma once  // complier dont process this file more than once

class Command {
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
};