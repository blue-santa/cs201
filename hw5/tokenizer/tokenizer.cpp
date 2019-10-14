/**
 * tokenizer.cpp
 * CS 201
 * Bryan Beus
 * October 12, 2019
 * The function definition file
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

unsigned StringToTokensWS(const string &input, vector<string> &tokens, bool &isFinished) {

    string temp; 
    istringstream instream(input);

    if (!instream) {
        cout << "No string provided" << endl;
    }
    
    // Might need something here to break up the line by whitespaces?

    while (!instream.eof()) {
        instream >> temp;
        isFinished = containsEnd(temp);
        tokens.push_back(temp);

        if (isFinished) {
            break;
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
    vector<char> special {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '+', '-', '*', '/', '=', '%'};

    vector< vector<char> > vv {integers, identifier, special};

    for (auto token: tokens) {
        if (longest_length < token.length())
            longest_length = token.length();
    }

    for (auto token: tokens) {
        string potType;
        bool res = false;
        vector<string> potTypes {"integer", "identifier", "special"};

        if (!res) { 
            // Also tests to ensure that the token has a length > 0
            potType = "whitespace";
            checkWhitespace(token, potType, res, longest_length); 
        } 

        if (!res) {
            potType = "string";
            checkStringLiteral(token, potType, res, longest_length);
        } 

        int i {0};
        while (!res && i < 3) {
            potType = potTypes.at(i);
            checkType(token, potType, res, longest_length, vv.at(i)); 
            i++;
        } 
        
        if (!res) {
            string unknown = "unknown";
            printType(token, longest_length, unknown);
        } 

    } 
}

int checkType(string &token, string &potType, bool &res, const size_t &longest_length, vector<char> &v) { 

    size_t tokenLength = token.length();

    bool isType = true;

    size_t i {0};

    while (i < tokenLength && isType == true) { 

        if (find(v.begin(), v.end(), token.at(i)) == v.end()) {
            isType = false;
        }

        ++i;
    }

    if (isType) {
        res = true;
        printType(token, longest_length, potType);
    }

    return 0;
}

void checkWhitespace(string &token, string &potType, bool &res,  const size_t &longest_length) { 
    size_t tokenLength = token.length();
    if (!tokenLength || token == " ") {
        res = true;
        printType(token, longest_length, potType);
    } 
}

void checkStringLiteral(string &token, string &potType, bool &res,  const size_t &longest_length) {
    bool isStringLiteral = false;

    size_t tokenLength = token.length();

    if ((token.at(0) == '"') && (token.at(tokenLength - 1) == '"')) {
        isStringLiteral = true;
    }

    if (isStringLiteral) {
        res = true;
        escapeQuotes(token, tokenLength);
        printType(token, longest_length, potType);
    }
}

void escapeQuotes(string &token, size_t &tokenLength) {
    token.insert(0, "\\");
    token.insert(tokenLength, "\\");
}

void printType(string &token,  const size_t &longest_length, string &potType) {
    int necessary_width = 20 - potType.length(); 
    cout << "[" << potType << "]" << string(necessary_width, ' ') << '"' << token << '"' << endl; 
}
