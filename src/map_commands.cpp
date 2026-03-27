#include "map_commands.h"

#include <iostream>
#include <fstream>

using namespace std;

void Command::echo(const vector<string>& args) {
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

void Command::coutfile(const vector<string>& args) {
    for (int i = 0; i < args.size(); i++) {

    }
}