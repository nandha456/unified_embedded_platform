#include "build_command.hpp"
#include "../core/build/Builder.hpp" //.. ->src/ /.. -> unixtron

int BuildCommand::execute()
{
    Builder builder;
    return builder.build() ? 0 : 1;
}