/**
 * userInput.hpp
 * CS 201
 * Bryan Beus
 * September 30, 2019
 * Header file for the user input project
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

#ifndef USERINPUTHPP
#define USERINPUTHPP


void exercise1(vector<string> &userInput);

void exercise2(vector<string> &userInput, vector<string> &userInput2);

void exercise3(vector<string> &userInput, vector<string> &userInput3); 

void requestUserInput(vector<string> &userInput);

void printUserInput(vector<string> &userInput);

void filterInput1(vector<string> &userInput, vector<string> &userInput2);

void filterInput2(vector<string> &userInput, vector<string> &userInput3);


#endif
