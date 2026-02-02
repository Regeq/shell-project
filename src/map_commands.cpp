#include "map_commands.h"

void cmd_echo (const vector<string>& args) 
{
	for (int i = 0; i < args.size(); i++)
	{
		if (args[i] == "\n") 
		{
			cout << endl; 
		} else 
		{ 
			cout << args[i]; 
		}

	}
}

void cmd_echo2(const vector<string>& args)
{
	cout << "pracuje";
}