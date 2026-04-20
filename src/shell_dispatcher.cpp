#include "../include/shell_dispatcher.h"
#include <iostream>

static std::unordered_map<std::string, Handler> command_map;

void startDispatching(Shell& shell)
{
    command_map.clear();

    command_map["russrou"] = [&shell](const Args& a) { shell.game.russrou(a); };
    command_map["diceroll"] = [&shell](const Args& a) { shell.game.diceroll(a); };
}

void dispatch(const std::string& command, const Args& args)
{
    auto it = command_map.find(command);
    if (it == command_map.end()) {
        std::cerr << "Unknown command: " << command << "\n";
        return;
    }
    it->second(args);
}