#include <iostream>
#include <unordered_map>
#include <vector>
#include "map_commands.cpp"
#include <string>

using namespace std;

extern string command;
extern vector<string> args;

using SCommand = void(*)(const vector<string>&);

void dispatch (string command, vector<string> args) {
unordered_map<string, SCommand> command_map;

command_map["echo"] = &cmd_echo;
}