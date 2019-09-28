/**
 * std_lib_test.cpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * Test program for the Standard Library Common Functions
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

#include "std_lib.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

int main(int argc, char **argv) {

    // Declare variable to hold user input

    int userInput;

    // Test clearConsole() function

    clearConsole();

    // Print reports

    cout << "Console should be cleared." << endl << endl;

    cout << "Please input a non-integer value first, to test the clearCin() function. Then input a valid integer second: ";

    // Initiate endless while loop to wait for user input types
    // First type should be invalid, second should be valid

    while (true) {

        cin >> userInput;

        if (cin.fail()) {
            clearCin();
            cout << "You provided an invalid input. Good job. Now, let's try a valid integer: ";
        } else {
            break;
        }
    }

    // Test waitForContinue() function

    waitForContinue();

    // Print reports

    cout << "\nThe waitForContinue() function should have functioned properly." << endl;
    cout << "Testing final function: keep_window_open()." << endl << endl;

    // Test keep_window_open() function and end program

    keep_window_open();

    return 0;
}
