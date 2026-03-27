#include <iostream>
#include <string>
#include <vector>

#include "shell_dispatcher.h"

using namespace std;

// Tokenizes input
static vector<string> tokenize_input(const string& input_shell)
{
    vector<string> tokenized_shell_input;
    string token_build;
    bool quoted = false;

    for (char c : input_shell)
    {
        if (c == '"')
        {
            quoted = !quoted;
        }
        else if (isspace(static_cast<unsigned char>(c)) && !quoted)
        {
            if (!token_build.empty())
            {
                tokenized_shell_input.push_back(token_build);
                token_build.clear();
            }
        }
        else
        {
            token_build += c;
        }
    }

    if (!token_build.empty())
        tokenized_shell_input.push_back(token_build);

    return tokenized_shell_input;
}

int main()
{
    Shell shell;
    startDispatching(shell);

    const string device = "esko@eskotop";
    const string shell_symbol = " >>";
    string input_shell, command, dir = "Desktop";

    while (true)
    {
        cout << "\033[36m" << device
             << "\033[31m" << " ~/" << dir
             << "\033[35m" << shell_symbol
             << " \033[0m";

        getline(cin, input_shell);

        if (input_shell == "exit")
            break;

        auto tokens = tokenize_input(input_shell);
        if (tokens.empty())
            continue;

        command = tokens[0];
        vector<string> args(tokens.begin() + 1, tokens.end());

        dispatch(command, args);
    }

    return 0;
}
