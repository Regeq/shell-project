#include <iostream>
#include <string>
#include <vector>
#include <format>

#include "../include/shell_dispatcher.h"
#include "db/db_handling.h"

#define CYAN "\033[36m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

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
    Database db;
    startDispatching(shell);

    const string currentCharacter = "NULL";
    const string shell_symbol = " >>";
    string input_shell, command;
    int hp = NULL, lvl = NULL;

    while (true)
    {
        cout << CYAN << currentCharacter
             << RED << format(" [{} HP | LVL {}]", hp, lvl)
             << PURPLE << shell_symbol
             << RESET;

        getline(cin, input_shell);

        if (input_shell == "exit")
            //  db.save();
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
