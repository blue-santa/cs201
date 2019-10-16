/**
 * tokenizer.hpp
 * CS 201
 * Bryan Beus
 * October 12, 2019
 * Header file
 */

#ifndef _TOKENIZER_HPP_
#define _TOKENIZER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;
    using std::string;
    using std::noskipws;
    using std::getline;
    using std::istringstream;
    using std::find;

    // Read a line from the user
    bool ReadLine(string &input);

    // Convert a string to a token
    unsigned StringToTokensWS(const string &input, vector<string> &tokens, bool &isFinished);

    // Check if a token contains a variation of the word "end"
    bool containsEnd(string &testSubject);

    // Analyze the content of a token and print its type to the screen
    void AnalyzeTokens(const vector<string> &tokens);

    // Check a specific token against a specific type, as provided in a vector of potential chars
    int checkType(string &token, string &potType, bool &res, const size_t &longest_length, vector<char> &v);

    // Check if a token is a whitespace type
    void checkWhitespace(string &token, string &potType, bool &res,  const size_t &longest_length);

    // Check if a token is a string literal
    void checkStringLiteral(string &token, string &potType, bool &res,  const size_t &longest_length);

    // Escape quotation marks within a token
    void escapeQuotes(string &token, size_t &tokenLength);

    // Print a line of type and token to the console
    void printType(string &token,  const size_t &longest_length, string &potType);

#endif
