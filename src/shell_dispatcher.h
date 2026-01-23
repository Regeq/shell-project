#include <unordered_map>
#include "map_commands.h"

using namespace std;
using SCommand = void(*)(const vector<string>&);

void startDispatching();
void dispatch(string command, vector<string> args);