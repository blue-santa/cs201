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

// #include "tokenizer.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::istringstream;
using std::find;

bool ReadLine(string &input);
unsigned StringToTokensWS(string &input, vector<string> &tokens, bool &isFinished);
bool containsEnd(string &testSubject);
void AnalyzeTokens(const vector<string> &tokens);
int checkType(string &token, string &type, bool &res, vector<char> &v);
void checkWhitespace(string &token, string &type, bool &res);

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

    AnalyzeTokens(tokens);

    return 0;
}

bool ReadLine(string &input) { 
    while (true) {
        string line;
        getline(cin, line); 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please try again: ";
        } else if (!cin || line == "") {
            return false;
        } else { 
            input = line;
            return true;
        }
    }
}

unsigned StringToTokensWS(string &input, vector<string> &tokens, bool &isFinished) {

    string temp; 
    istringstream instream(input);

    if (!instream) {
        cout << "No string provided" << endl;
    }
    
    // Might need something here to break up the line by whitespaces?

    while (!instream.eof()) {
        instream >> temp;
        isFinished = containsEnd(temp);

        if (isFinished) {
            break;
        } else {
            tokens.push_back(temp);
        }
    } 

    if (!isFinished)
        tokens.push_back(" ");

    size_t tokensSize = tokens.size();

    return tokensSize;
}

bool containsEnd(string &testSubject) {

    string temp = testSubject;
    transform(temp.begin(), temp.end(), temp.begin(), tolower);
    if (temp == "end") {
        return true;
    }

    return false;
}

void AnalyzeTokens(const vector<string> &tokens) {
    size_t longest_length = 0;

    vector<char> integers {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<char> identifier {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_'};
    vector<char> string_literal {'"'};
    vector<char> special {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '+', '-', '*', '/', '=', '%'};

    for (auto token: tokens) {
        if (longest_length < token.length())
            longest_length = token.length();
    }

    for (auto token: tokens) {
        bool res = false;

        string type;

        checkType(token, type, res, integers);

        if (res) {
            type = "integer";
        } else {
            checkType(token, type, res, identifier);
        }

        if (res && type.empty()) {
            type = "identifier";
        } else {
            checkType(token, type, res, string_literal);
        }

        if (res && type.empty()) {
            type = "string_literal";
        } else {
            checkWhitespace(token, type, res);
        }

        if (res && type.empty()) {
            type = "whitespace";
        } else {
            checkType(token, type, res, special);
        }

        if (res && type.empty()) {
            type = "special";
        } 
        
        if (!res) {
            type = "unknown";
        } 

        int necessary_width = longest_length + 35 - token.length() - type.length(); 

        cout << "[" << type << "]" << string(necessary_width, ' ') << token << endl; 
    } 
}

int checkType(string &token, string &type, bool &res, vector<char> &v) { 

    size_t tokenLength = token.length();

    bool isType = true;
    size_t vSize = v.size();

    if (!tokenLength) {
        return 0;
    }

    int i {0};

    while (i < tokenLength && isType == true) { 

        if (find(v.begin(), v.end(), token.at(i)) == v.end()) {
            isType = false;
        }

        ++i;
    }

    if (isType) {
        res = true;
    }

    return 0;
}

void checkWhitespace(string &token, string &type, bool &res) {
    bool isWhitespace = true;

    if ((token.at(0) != ' ') && (token.length() != 1))
        isWhitespace == false;

    if (isWhitespace) {
        res = true;
    }
}

