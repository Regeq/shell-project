#include <iostream>
#include <string>
#include <vector>
#include "shell_dispatcher.cpp"

using namespace std;

// Tokenizes input
vector<string> static tokenize_input(const string& input_shell) {
    vector<string> tokenized_shell_input;
    string token_build;
    bool quoted = false;

    for (char c : input_shell) {
        if (c == '"') {
            // Toggles between true/false 
            quoted = !quoted;
        }
        // Checks for any white spaces
        else if (isspace(c) && !quoted) {
            // Checks if token to waiting to push is not empty, if it is not, it pushes token to the vector
            if (!token_build.empty()) {
            tokenized_shell_input.push_back(token_build);
            token_build.clear();
            }
        }
        else {
            token_build += c;
        }
    };

    // Pushes anything left in token_build after filling loop
    if (!token_build.empty()) {
        tokenized_shell_input.push_back(token_build);
    };

    return tokenized_shell_input;
};

int main()
{
    const string device = "esko@eskotop", shell_symbol = " >>";
    string input_shell, command, dir = "Desktop";
    vector<string> tokenized_shell_input, args;

    while (true) {
        // Clears temporary vector
        tokenized_shell_input.clear();

        // Prints prompt, gets input, saves it as input_shell
        cout << "\033[36m" << device << "\033[31m" << " ~/" << dir << "\033[35m" << shell_symbol << ' ' << "\033[0m";
        getline(cin, input_shell);

        // Checks input for exit, case sensitive
        if (input_shell == "exit") {break;}

        // Tokenizes input, if tokenized input (vector) is empty (ie enter) continues without passing 
        tokenized_shell_input = tokenize_input(input_shell);
        if (tokenized_shell_input.empty()) {continue;} 

        // Takes tokenized input and converts it as first field in array is command, rest are args
        command = tokenized_shell_input[0];
        args = vector<string>(tokenized_shell_input.begin() + 1, tokenized_shell_input.end());

        // Calls function from shell_dispatcher, processes command and args
        dispatch(command, args);
    }
    
    return 0;
}