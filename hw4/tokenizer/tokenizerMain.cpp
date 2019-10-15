/**
 * tokenizerMain.cpp
 * CS 201
 * Bryan Beus
 * October 12, 2019
 * The main file for the tokenizer project
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#include "tokenizer.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::istringstream;
using std::find;

int main(int argc, char **argv) {

    // Declare input vector<string> that will continually capture user input
    string input;

    // Declare vector<string> tokens that will collect all tokens from every input
    vector<string> tokens;

    // Declare bool for tracking user input of "end"
    bool isFinished;

    // Request user input 
    cout << "Please type text. When you are done, type any variation of \"End\": " << endl;

    while (true) {

        // Capture user input
        ReadLine(input);

        // Iterate through input and place ordered responses into tokens container
        StringToTokensWS(input, tokens, isFinished);

        // Test whether there is a new token that is any combination of the string "end"
        // If so, break the endless while loop 
        if (isFinished) {
            break;
        } 
    }

    // Analyze tokens
    AnalyzeTokens(tokens);

    return 0;
}
