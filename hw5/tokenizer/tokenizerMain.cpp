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

#define MAX_INPUT_LENGTH    300

bool ReadLine(string &input);
unsigned StringToTokensWS(string &input, vector<string> &tokens, bool &isFinished);
bool containsEnd(string &testSubject);
void AnalyzeTokens(const vector<string> &tokens);
void checkInt(string &token, string &type, bool &res);
void checkIdentifier(string &token, string &type, bool &res);
void checkString(string &token, string &type, bool &res);
void checkWhitespace(string &token, string &type, bool &res);
void checkSpecial(string &token, string &type, bool &res);

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
        tokens.push_back("");

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
    string temp;
    bool res = false;
    size_t longest_length = 0;

    for (auto token: tokens) {
        if (longest_length < token.length())
            longest_length = token.length();
    }

    for (auto token: tokens) {
        string type;

        checkInt(token, type, res);

        if (!res) {
           checkIdentifier(token, type, res); 
        }

        if (!res) {
            checkString(token, type, res);
        }

        if (!res) {
            checkWhitespace(token, type, res);
        }

        if (!res) {
            checkSpecial(token, type, res);
        }

        if (!res) {
            type = "unknown";
        } 

        int necessary_width = longest_length + 15 - token.length(); 

        cout << "[" << type << "]" << string(necessary_width, ' ') << token << endl; 
    } 
}

void checkInt(string &token, string &type, bool &res) { 
    bool isInt = true;

    vector<char> identifiers {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int i {0};

    size_t tokenLength = token.length();
    size_t identifiersSize = identifiers.size();

    while (i < tokenLength && isInt == true) {

        for (size_t i {0}; i < identifiersSize ; i++) { 
            if (find(identifiers.begin(), identifiers.end(), token.at(i)) == identifiers.end()) {
                isInt = false;
            }
        }

        ++i;
    }

    if (isInt) {
        type = "integer";
        res = true;
    }
}

void checkIdentifier(string &token, string &type, bool &res) { 
    bool isIdent = true;

    vector<char> identifiers {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                                "u", "v", "w", "x", "y", "z",
                                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                                "U", "V", "W", "X", "Y", "Z",
                                "_"};

    int i {0};

    size_t tokenLength = token.length();
    size_t identifiersSize = identifiers.size();

    while (i < tokenLength && isIdent == true) {

        for (size_t i {0}; i < identifiersSize; i++) {
            if (find(identifiers.begin(), identifiers.end(), token.at(i)) == identifiers.end()) {
                isIdent = false;
            }
        }

        ++i;
    }

    if (isIdent) {
        type = "identifier";
        res = true;
    }
}

void checkString(string &token, string &type, bool &res) {
    bool isString = true;

    vector<char> identifiers {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                                "u", "v", "w", "x", "y", "z",
                                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                                "U", "V", "W", "X", "Y", "Z",
                                "_", "\""};

    int i {0};

    size_t tokenLength = token.length();
    size_t identifiersSize = identifiers.size();

    while (i < tokenLength && isString == true) {

        for (size_t i {0}; i < identifiersSize; i++) {
            if (find(identifiers.begin(), identifiers.end(), token.at(i)) == identifiers.end()) {
                isString = false;
            }
        }

        ++i;
    }

    if (token.at(0) != '\"' || token.at(tokenLength - 1) != '\"') {
        isString = false;
    }

    if (isString) {
        type = "string literal";
        res = true;
    }
}

void checkWhitespace(string &token, string &type, bool &res) {
    bool isWhitespace = true;

    if (token != " ")
        isWhitespace == false;

    if (isWhitespace) {
        type = "whitespace";
        res = true;
    }
}

void checkSpecial(string &token, string &type, bool &res) {
    bool hasSpecial = true;

    vector<char> identifiers {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                                "u", "v", "w", "x", "y", "z",
                                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                                "U", "V", "W", "X", "Y", "Z",
                                "_", "\"", "+", "-", "*", "/", "=", "%"};

    int i {0};

    size_t tokenLength = token.length();
    size_t identifiersSize = identifiers.size();

    while (i < tokenLength && hasSpecial == true) {

        for (size_t i {0}; i < identifiersSize; i++) {
            if (find(identifiers.begin(), identifiers.end(), token.at(i)) == identifiers.end()) {
                hasSpecial = false;
            }
        }

        ++i;
    }

    if (hasSpecial) {
        type = "special characters";
        res = true;
    }
}
