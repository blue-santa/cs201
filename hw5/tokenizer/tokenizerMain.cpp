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
using std::find;

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

unsigned StringToTokenWS(string &input, vector<string> &tokens, bool &isFinished) {

    string temp;

    istringstream instream(input);

    if (!instream) {
        cout << "err" << endl;
    }
    
    while (!instream.eof()) {
        instream >> temp;
        isFinished = containsEnd(temp);

        if (isFinished) {
            break;
        } else {
            tokens.push_back(temp);
        }
    }

    tokens.push_back("");

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

bool containsEnd(string &testSubject) {

    string temp = testSubject;
    transform(temp.begin(), temp.end(), temp.begin(), tolower);
    if (temp == "end") {
        return true
    }

    return false;
}

void AnalyzeTokens(const vector<string> &tokens) {
    string temp;
    bool res = false;
    size_t longest_length = 0;

    for (auto token: tokens) {
        if (longest_length < token.size())
            longest_length = token.size();
    }

    for (auto token: tokens) {
        string type;

        res = checkInt(token, type, res);

        if (!res) {
           res = checkIdentifier(token, type, res); 
        }

        if (!res) {
            res = checkString(token, type, res);
        }

        if (!res) {
            res = checkWhitespace(token, type, res);
        }

        if (!res) {
            res = checkSpecial(token, type, res);
        }

        if (!res) {
            type = "unknown";
        } 

        size_t necessary_width = longest_length + 15 - token.size();
        cout << "[" << type << "]" << string(necessary_width, " ") << token << endl; 
    } 
}

void checkInt(string &token, string &type, bool &res) { 
    bool isInt = true;

    vector<string> integers {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int i {0};

    while (i < token.size() && isInt == true)

        for (size_t i {0}; i < integers.size(); i++) {
            size_type testPresent = (find(integers.begin(), integers.end(), token.charAt(i)));
            if (testPresent == string::npos) {
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

    vector<string> identifiers {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                                "u", "v", "w", "x", "y", "z",
                                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                                "U", "V", "W", "X", "Y", "Z",
                                "_"};

    int i {0};

    while (i < token.size() && isIdent == true)

        for (size_t i {0}; i < identifiers.size(); i++) {
            size_type testPresent = (find(identifiers.begin(), identifiers.end(), token.charAt(i)));
            if (testPresent == string::npos) {
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

    vector<string> identifiers {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                                "u", "v", "w", "x", "y", "z",
                                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                                "U", "V", "W", "X", "Y", "Z",
                                "_", "\""};

    int i {0};

    while (i < token.size() && isString == true)

        for (size_t i {0}; i < identifiers.size(); i++) {
            size_type testPresent = (find(identifiers.begin(), identifiers.end(), token.charAt(i)));
            if (testPresent == string::npos) {
                isString = false;
            }
        }

        ++i;
    }

    size_t tokenSize = token.size();
    if (token.charAt(0) != "\"" || token.charAt(tokenSize) != "\"") {
        isString = false;
    }

    if (isString) {
        type = "string literal";
        res = true;
    }
}

void checkWhitespace(string &token, string &type, bool &res) {
    bool isString = true;

    vector<string> identifiers {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                                "u", "v", "w", "x", "y", "z",
                                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                                "U", "V", "W", "X", "Y", "Z",
                                "_", "\""};

    int i {0};

    while (i < token.size() && isString == true)

        for (size_t i {0}; i < identifiers.size(); i++) {
            size_type testPresent = (find(identifiers.begin(), identifiers.end(), token.charAt(i)));
            if (testPresent == string::npos) {
                isString = false;
            }
        }

        ++i;
    }

    size_t tokenSize = token.size();
    if (token.charAt(0) != "\"" || token.charAt(tokenSize) != "\"") {
        isString = false;
    }

    if (isString) {
        type = "string literal";
        res = true;
    }
}

void checkSpecial(string &token, string &type, bool &res) {
}

int main(int argc, char **argv) {

    // Declare input vector<string> that will continually capture user input
    vector<string> input;

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
        StringToTokensWS(input, tokens);

        // Test whether there is a new token that is any combination of the string "end"
        // If so, break the endless while loop 
        if (isFinished) {
            break;
        } 
    }

    AnalyzeTokens(tokens);

    return 0;
}

