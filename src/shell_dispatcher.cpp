#include "shell_dispatcher.h"
#include "map_commands.h"

#include <unordered_map>
#include <iostream>

static std::unordered_map<std::string, SCommand> command_map;

void startDispatching()
{
    command_map.clear();
    command_map["echo"]  = &cmd_echo;
}

void dispatch(const std::string& command,
              const std::vector<std::string>& args)
{
    auto it = command_map.find(command);
    if (it == command_map.end())
    {
        std::cerr << "Unknown command: " << command << std::endl;
        return;
    }

    it->second(args);
}
