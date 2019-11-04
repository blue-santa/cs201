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

// Read a line from user input
bool ReadLine(string &input) { 
    while (true) {
        string line;
        getline(cin, line); 

        // If user input is invalid, repeat loop
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please try again: ";

        // If the user provides no input, return false
        } else if (!cin || line == "") {
            return false;

        // Otherwise, set input to user input (line) and end function
        } else { 
            input = line;
            return true;
        }
    }
}

// Convert a string to a token
unsigned StringToTokensWS(const string &input, vector<string> &tokens, bool &isFinished) {

    // Initiate stream to parse user input
    string temp; 
    istringstream instream(input);

    // If the stream is empty, provide warning in console
    if (!instream) {
        cout << "No string provided" << endl;
    }
    
    // Iterate through provided input, pushing each word into a token
    // If we encounter the word "end" via the containsEnd() function, end the loop
    while (!instream.eof()) {
        instream >> temp;
        isFinished = containsEnd(temp);
        tokens.push_back(temp); 
        if (isFinished) {
            break;
        }
    } 

    // For each end of line, push an empty string, as per the instructions
    if (!isFinished)
        tokens.push_back("");

    // Set token size
    size_t tokensSize = tokens.size(); 
    return tokensSize;
}

// Check if the test subject contains the word "End"
bool containsEnd(string &testSubject) {

    // Transfer value of test subject to temp string
    // Change all uppercase values to lower case values in temp
    string temp = testSubject;
    transform(temp.begin(), temp.end(), temp.begin(), tolower);

    // If the value is the word "end", return true, else return false
    if (temp == "end") {
        return true;
    } 
    return false;
}

// Analyze a token to determine its type and print a value to the screen
void AnalyzeTokens(const vector<string> &tokens) {

    // Create vector of vectors that contains all values for which we are testing
    vector<char> integers {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<char> identifier {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_'};
    vector<char> other {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '+', '-', '*', '/', '=', '%'}; 
    vector< vector<char> > vv {integers, identifier, other};

    // Create a list of names of the potential types for which we test
    vector<string> potTypes {"integer", "identifier", "other"};

    // Discover longest possible length for a token, for formatting
    size_t longest_length = 0;
    for (auto token: tokens) {
        if (longest_length < token.length())
            longest_length = token.length();
    }

    // Iterate through each token to check its type, and print the type to the console, along with the token value
    for (auto token: tokens) {

        // Declare a potential-type variable, potType, to hold the name of each value we are currently testing
        string potType;
        
        // Assume each test is false, unless a true value is returned
        bool res = false;

        // Check that for the token as a whitespace first, as this is the simplest
        if (!res) { 
            // Also test to ensure that the token has a length > 0
            potType = "whitespace";
            checkWhitespace(token, potType, res, longest_length); 
        } 

        // Check if the token is a string literal
        if (!res) {
            potType = "string";
            checkStringLiteral(token, potType, res, longest_length);
        } 

        // Check each of the remaining three types with the checkType() function and an while loop
        // Cease while loop if a match is found
        int i {0};
        while (!res && i < 3) {
            potType = potTypes.at(i);
            checkType(token, potType, res, longest_length, vv.at(i)); 
            i++;
        } 
        
        // If we have not yet found a positive result, set "unknown" as the type
        if (!res) {
            string unknown = "unknown";
            printType(token, longest_length, unknown);
        } 

    } 
}

// Check a provided token to see if it belongs to a specific types, as provided by a vector of possible chars
int checkType(string &token, string &potType, bool &res, const size_t &longest_length, vector<char> &v) { 

    // Set a variable to token length
    size_t tokenLength = token.length();

    // Assume type is true by default
    bool isType = true;

    // Initiate endless while loop to test 
    size_t i {0}; 
    while (i < tokenLength && isType == true) { 

        // If an instance occurs where a char in the token cannot match the provided vector of valid values, end the loop and set isType to false
        if (find(v.begin(), v.end(), token.at(i)) == v.end()) {
            isType = false;
        } 
        ++i;
    }

    // If the isType value is still true, set res to true and print the value of the type to the screen
    if (isType) {
        res = true;
        printType(token, longest_length, potType);
    }

    return 0;
}

// Check if provided token is only white space
void checkWhitespace(string &token, string &potType, bool &res,  const size_t &longest_length) { 

    // Set variable to size of token length
    size_t tokenLength = token.length();

    // Test if the token has length, or if it is only a single whitespace char
    // If so, set res to true and print type
    if (!tokenLength || token == " ") {
        res = true;
        printType(token, longest_length, potType);
    } 
}

// Check if the provided token is a string literal
void checkStringLiteral(string &token, string &potType, bool &res,  const size_t &longest_length) {

    // Assume token is not a string literal by default
    bool isStringLiteral = false;

    // Set variable to size of token length
    size_t tokenLength = token.length();

    // If the first and last tokens are a double quotation mark, set isStringLiteral to true
    if ((token.at(0) == '"') && (token.at(tokenLength - 1) == '"')) {
        isStringLiteral = true;
    }

    // if this is a string literal:
    // set res to true
    // Change all quotation marks in the token to escaped marks
    // Print the type to the console
    if (isStringLiteral) {
        res = true;
        escapeQuotes(token, tokenLength);
        printType(token, longest_length, potType);
    }
}

// Change a provided token so that all quotation marks are escaped
void escapeQuotes(string &token, size_t &tokenLength) {
    token.insert(0, "\\");
    token.insert(tokenLength, "\\");
}

// Print a provided token to the screen, along with its type name
void printType(string &token,  const size_t &longest_length, string &potType) {
    int necessary_width = 20 - potType.length(); 
    cout << "[" << potType << "]" << string(necessary_width, ' ') << '"' << token << '"' << endl; 
}
