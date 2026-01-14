#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern string command;
extern vector<string> args;

void cmd_echo (const vector<string>& args) {cout << "facha";}