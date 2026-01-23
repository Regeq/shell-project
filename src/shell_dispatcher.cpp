#include <unordered_map>
#include "shell_dispatcher.h"

unordered_map<string, SCommand> command_map;

void startDispatching() 
{
	command_map["echo"] = &cmd_echo;
	command_map["echo2"] = &cmd_echo2;
}

void dispatch (string command, vector<string> args)
{
	auto it = command_map.find(command); // iterator
	if (it == command_map.end())
		cerr << "Unknown command: " << command << endl;
	else 
		it->second(args);
}