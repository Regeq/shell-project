#pragma once

#include "map_commands.h"

#include <string>
#include <vector>

using SCommand = void (Command::*)(const std::vector<std::string>&);

void startDispatching();
void dispatch(const std::string& command,
              const std::vector<std::string>& args);
