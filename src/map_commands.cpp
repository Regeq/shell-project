#include "map_commands.h"

#include <iostream>
#include <fstream>
#include <random>

using namespace std;

/*

 Games

 */

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
    cout << endl;
}

void Command::coutfile(const vector<string>& args) {
    for (int i = 0; i < args.size(); i++) {

    }
}

/*

 Games

 */

void Game::russrou(const vector<string>& args)
{
    int arg_value;
    char rr_answer;
    for (int i = 0; i < args.size(); i++) {
        if (args[i] == "-cc") {
            arg_value = stoi(args[i + 1]);
        }
        /*if (args[i] == "-bc") {
            arg_value = stoi(args[i + 1]);
        }
        */
    }
    int bullet_pos = rand() % arg_value;

    for (int i = 0; i < arg_value; i++) {
        cout << "Do you pull or chicken out (y/q): ";
        cin >> rr_answer;
        cout << "\n";

        if (rr_answer == 'q') {
            cout << "Pussy...";
            break;
        } else {
            if (i == bullet_pos) {
                cout << "You died.\n";
                break;
            } else {
                cout << "You get to see the light of the day once again.\n";
            }
        }
    }
}