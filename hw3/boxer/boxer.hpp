/**
 * boxer.hpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * Header file for the main boxer project
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

#ifndef BOXERHPP
#define BOXERHPP

    void waitForContinue();

    void clearConsole();

    void clearCin();

    void printFull(int layers, size_t phraseLength);

    void printEmpty(int layers, size_t phraseLength);

    void printBox(int layers, string & phrase);

    void requestLayers(int & layers, bool & contLoop);

    void requestPhrase(string & phrase); 

#endif
