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

    bool ReadLine(string &input);

    unsigned StringToTokensWS(const string &input, vector<string> &tokens, bool &isFinished);

    bool containsEnd(string &testSubject);

    void AnalyzeTokens(const vector<string> &tokens);

    int checkType(string &token, string &potType, bool &res, const size_t &longest_length, vector<char> &v);

    void checkWhitespace(string &token, string &potType, bool &res,  const size_t &longest_length);

    void checkStringLiteral(string &token, string &potType, bool &res,  const size_t &longest_length);

    void escapeQuotes(string &token, size_t &tokenLength);

    void printType(string &token,  const size_t &longest_length, string &potType);

#endif
