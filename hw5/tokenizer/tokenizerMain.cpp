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

#include "tokenizer.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::istringstream;

#define MAX_INPUT_LENGTH    300;

bool ReadLine(string &input) {

    cin.getline(input, MAX_INPUT_LENGTH);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    } else if (!cin || temp == "") {
        return false;
    } else { 
        return true;
    }
}

unsigned StringToTokenWS(string &input, vector<string> &tokens) {

        istringstream instream(input.at(i));
        int num;
        instream >> num;
        if (!instream) {
            cout << "err" << endl;
        } else {
            cout << num * num << endl;
        }

    size_t tokenSize = tokens.size();

    if (tokens.size() <= sizeof(unsigned)) {
        tokenSize = static_cast<unsigned>(tokenSize);
    }

    return tokenSize;
}

bool containsEnd(vector<string> &tokens) {

    for (auto token: tokens) {
       string temp = token;
       transform(temp.begin(), temp.end(), temp.begin(), tolower);
       if (temp == "end") {
            return true
       }
    }
    return false;
}

void AnalyzeTokens(const vector<string> &tokens) {

}

int main(int argc, char **argv) {

    // Declare input vector<string> that will continually capture user input
    vector<string> input;

    // Declare vector<string> tokens that will collect all tokens from every input
    vector<string> tokens;

    // Request user input 
    cout << "Please type text. When you are done, type any variation of \"End\": " << endl;

    while (true) {

        // Capture user input
        ReadLine(input);

        // Add a blank space when the line is complete
        // TO DO
        
        // Iterate through input and place ordered responses into tokens container
        StringToTokensWS(input, tokens);

        // Test whether there is a new token that is any combination of the string "end"
        // If so, break the endless while loop 
        bool isFinished = containsEnd(tokens);
        if (isFinished) {
            break; 
        } 
    }

    AnalyzeTokens(tokens);

    return 0;
}

