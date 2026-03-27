#pragma once

#include <vector>
#include <string>

class Command {
public:
    void echo(const std::vector<std::string>& args);
    void coutfile(const std::vector<std::string>& args);
};

class Game {
public:
    void russrou(const std::vector<std::string>& args);
};