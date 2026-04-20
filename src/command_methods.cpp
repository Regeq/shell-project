#include "../include/command_methods.h"
#include <random>

using namespace std;

bool Game_methods::in_vector(const std::vector<int>& v, int number) {
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == number) {
            return true;
        }
    }
    return false;
}

int Game_methods::random_number(int min, int max) {
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}