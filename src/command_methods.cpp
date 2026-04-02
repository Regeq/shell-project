#include "command_methods.h"

using namespace std;

bool Game_methods::in_vector(const std::vector<int>& v, int number) {
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == number) {
            return true;
        }
    }
    return false;
}