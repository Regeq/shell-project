#include "shell_dispatcher.h"
#include "map_commands.h"

#include <unordered_map>
#include <iostream>

using namespace std;

static unordered_map<string, SCommand> command_map;

void startDispatching()
{
    command_map.clear();
    command_map["echo"]  = &cmd_echo;
}

void dispatch(const string& command,
              const vector<string>& args)
{
    auto it = command_map.find(command);
    if (it == command_map.end())
    {
        cerr << "Unknown command: " << command << endl;
        return;
    }

    it->second(args);
}
