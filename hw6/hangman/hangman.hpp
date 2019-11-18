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

void clearConsole();

void printCurrentProgress(vector<pair<char, bool>> &quoteStatus);

bool printCurrentHangmanState(vector<pair<string, bool>> &hangmanState, bool &isFinished);

bool promptUserInput(vector<pair<char, bool>> &quoteStatus, vector<pair<string, bool>> &hangmanState, bool &isFinished);

bool updateProgress(char &nextGuess, int &turns, vector<pair<char, bool>> &quoteStatus, bool &charFound);

bool promptUserInput(vector<pair<char, bool>> &quoteStatus, vector<pair<string, bool>> &hangmanState, bool &isFinished, int &turns, bool &charFound);

void updateHangmanState(vector<pair<string, bool>> &hangmanState, bool &charFound);

#endif
