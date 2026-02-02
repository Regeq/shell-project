#include "map_commands.h"

#include <iostream>

using namespace std;

void cmd_echo(const vector<string>& args)
{
    for (int i = 0; i < args.size(); i++)
    {
        if (args[i] == "\\n") {
            cout << endl;
        }
        else {
            cout << args[i] << ' ';
        }
    }
    cout << endl << endl;
}

