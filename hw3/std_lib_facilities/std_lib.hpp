/**
 * std_lib.hpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * Header file for Standard Library Common Functions
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

#ifndef STDLIBHPP
#define STDLIBHPP

// Wait for the user to indicate that they are ready to continue

inline void waitForContinue() {

    cout << endl << "Press enter to continue...";
    getchar();
}

// Clear the console

inline void clearConsole() {

        // Clear the console

    cout << "\033[2J\033[1;1H";

}

// Ensure the cin buffer is clear

inline void clearCin() {
    cin.clear();
    cin.ignore(1000, '\n');
}

// Keep the window open before exiting the program

inline void keep_window_open() {

    // Declare temp string to receive final exit value

    string tmp;

    // Clear cin

    clearCin();
    cout << "Press ENTER to exit the program." << endl;

    // Wait for user input

    getline(cin, tmp);

}

#endif
