#include "map_commands.h"

#include <iostream>

void cmd_echo(const std::vector<std::string>& args)
{
    for (const auto& arg : args)
        std::cout << arg << ' ';
    std::cout << std::endl;
}

void cmd_echo2(const std::vector<std::string>&)
{
    std::cout << "pracuje" << std::endl;
}
