#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "map_commands.h"

using Args = std::vector<std::string>;
using Handler = std::function<void(const Args&)>;

struct Shell {
    Game game;
};

void startDispatching(Shell& shell);
void dispatch(const std::string& command, const Args& args);