#ifndef _HANGMAN_HPP_
#define _HANGMAN_HPP_

/*
 * hangman.hpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Header file for hangman project in hw6
 */

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

// Clear the console
void clearConsole();

// Print the intended sentence with the current progress showing, and unguessed characters hidden
void printCurrentProgress(vector<pair<char, bool>> &quoteStatus);

// Print the current state of the hangman, including all captured body parts
bool printCurrentHangmanState(vector<pair<string, bool>> &hangmanState, bool &isFinished);

// Update the progress achieved towards the intended sentence
bool updateProgress(char &nextGuess, int &turns, vector<pair<char, bool>> &quoteStatus, bool &charFound);

// Prompt user input
bool promptUserInput(vector<pair<char, bool>> &quoteStatus, vector<pair<string, bool>> &hangmanState, bool &isFinished, int &turns, bool &charFound);

// Update the state of the hanged man's captured body parts
void updateHangmanState(vector<pair<string, bool>> &hangmanState, bool &charFound);

#endif
