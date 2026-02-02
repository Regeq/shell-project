#include "map_commands.h"

#include <iostream>

using namespace std;

void cmd_echo(const vector<string>& args)
{
    for (const auto& arg : args)
        cout << arg << ' ';
    cout << endl;
}

