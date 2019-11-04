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

#include "bulls-and-cows.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

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

// Quit the program
void quitProgram(Fl_Widget* obj, void*);

// Truncate a user-provided arbitrary number of characters from a string
void calculateBullsAndCows(Fl_Widget* obj, void*);

#endif

