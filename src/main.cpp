#include <cctype>
#include <format>
#include <iostream>
#include <string>
#include <vector>

#include "../include/shell_dispatcher.h"

#define CYAN "\033[36m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

using namespace std;

// Tokenizes input
static vector<string> tokenizeInput(const string& input_shell)
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

    const string currentCharacter = "NULL";
    const string shellSymbol = " >>";
    string inputShell, command;
    int hp = 0, lvl = 0;

    while (true)
    {
        cout << format("{}{} {}[{} HP | LVL {}] {}{}{} ",
                    CYAN, currentCharacter,
                    RED, hp, lvl,
                    PURPLE, shellSymbol, RESET);

        getline(cin, inputShell);

        if (inputShell == "exit")
            //  db.save();
            break;

        auto tokens = tokenizeInput(inputShell);
        if (tokens.empty())
            continue;

        command = tokens[0];
        vector<string> args(tokens.begin() + 1, tokens.end());

        dispatch(command, args);
    }

    return 0;
}