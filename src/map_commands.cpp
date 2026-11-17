#include "map_commands.h"
#include "../include/command_methods.h"

#include <iostream>

using namespace std;

Game_methods gm;

void Game::russrou(const vector<string>& args)
{
    int chamber_count, bullet_count, rr_temp;
    vector<int> bullet_pos;
    char rr_answer;
    bool cc_FlagPresent = false, bc_FlagPresent = false;

    for (int i = 0; i < args.size(); i++) {
        if (args[i] == "-cc") {
            chamber_count = stoi(args[i + 1]);
            cc_FlagPresent = true;
        }
    }

    for (int i = 0; i < args.size(); i++) {
        if (args[i] == "-bc") {
            bullet_count = stoi(args[i + 1]);
            if (bullet_count <= chamber_count) { break; }
            else {
                cout << "incorrect bullet count.";
                break;
            }
            bc_FlagPresent = true;
        }
    }

    while ((int)bullet_pos.size() < bullet_count) {
        rr_temp = rand() % chamber_count;
        if (!gm.in_vector(bullet_pos, rr_temp)) {
            bullet_pos.push_back(rr_temp);
        }
    }

    for (int i = 0; i < chamber_count; i++) {
        if (!cc_FlagPresent || !bc_FlagPresent) {
            if (!cc_FlagPresent) {
                cout << " -bc flag missing! Please specify the chamber count with the -cc flag.\n"; 
            }
            if (!bc_FlagPresent) {
                cout << " -bc flag missing! Please specify the bullet count with the -bc flag.\n";
            }
            break;
        }

        cout << "Do you pull or chicken out (y/q): ";
        cin >> rr_answer;
        cout << "\n";

        if (rr_answer == 'q') {
            cout << "Pussy...\n";
            break;
        } else {
            if (gm.in_vector(bullet_pos, i)) {
                cout << "You died.\n";
                break;
            } else {
                cout << "You get to see the light of the day once again.\n";
            }
        }
    }
}

void Game::diceroll(const vector<string>& args) {
    int sides, count, num;

    for (int i = 0; i < args.size(); i++) {
        if (args[i] == "-s") {
            sides = stoi(args[i + 1]);
        }
    }

    for (int i = 0; i < args.size(); i++) {
        if (args[i] == "-c") {
            count = stoi(args[i + 1]);
        }
    }


    for (int i = 0; i < count; i++) {
        num = gm.random_number(1, sides);
        cout << i+1 << ". dice rolled: " << num << endl;
    }
}

void Game::cointoss() {
    int rnum;

    rnum = gm.random_number(1,2);

    cout << rnum << endl;
}