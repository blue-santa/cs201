/*
 * caesar_cypher.hpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Header file for caesar cypher project in hw7 
 */

#ifndef _HANGMAN_HPP_
#define _HANGMAN_HPP_

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::make_pair;
using std::for_each;
using std::getline;
using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::find;
using std::map;
using std::setw;
using std::left;

// Capture the user input - for string portion
void capture_user_input_string(string& user_input, bool& isFinished);

// Test whether the user's input is a valid response
bool testUserInput_string(string &userInput, bool& isFinished);

void capture_user_input_int(int& shift_amount);

// Test whether the user's input is a valid response
bool testUserInput_int(string& userInput, int& shift_amount);

// Clear the console
void clearConsole();

// Wait for user response
void waitForContinue();

// Shift the user's method according to their requested cypher length
void shift_message(string& user_input, int& shift_amount, string& res_str);

#endif
