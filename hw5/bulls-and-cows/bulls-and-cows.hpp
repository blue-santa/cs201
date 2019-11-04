/**
 * bulls-and-cows.hpp
 * CS 201
 * Bryan Beus
 * October 14, 2019
 * Header file
 */

#ifndef USERINPUTHPP
#define USERINPUTHPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>
#include <stdlib.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::find;
using std::istringstream;
using std::stringstream;
using std::ifstream;
using std::rand;

// Test whether the user's input is a valid response
bool testUserInput(string &userInput);

// Clear the console 
void clearConsole();

// Wait for user response
void waitForContinue();

// Calculate the number of bulls and cows in the user's response
void calculateRes(string &pattern, string &userInput, int &bulls, int &cows);

// Set the pattern which the user must guess
void setPattern(string &pattern);

#endif
