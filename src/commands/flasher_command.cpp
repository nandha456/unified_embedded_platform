#include "flasher_command.hpp"

#include "../core/flash/flash.hpp"

int FlasherCommand::execute()
{
    Flasher flasher;

    return flasher.flash() ? 0 : 1;
}