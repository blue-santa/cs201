/**
 * kelvin.cpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * A program to correct the kelvin functions in the hw
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

// Original
// Did not have a few common console functions

// Wait for the user to indicate that they are ready to continue

void waitForContinue() {

    cout << endl << "Press enter to continue...";
    getchar();
}

// Clear the console

void clearConsole() {

        // Clear the console

    cout << "\033[2J\033[1;1H";

}

// Ensure the cin buffer is clear

void clearCin() {
    cin.clear();
    cin.ignore(1000, '\n'); 
}
// Converts Celsius to Kelvin

double ctok(double c) { 
    // Original
    //int k = c + 273.15;
    //
    //k must not be an int
    //
    //return k;

    // Revised

    // Create and return Kelvin variable k

    double k = c + 273.15;
    return k;
}

// Overloaded function for an invalid Celsius value

void ctok() { 

    // Ensure console is clear

    clearConsole();

    // Print report

    cout << "Input provided is not a valid Celsius temperature." << endl;
    cout << "Please provide a Celsius temperature at least -273.15 or above." << endl;
    
    // Wait for user to read output

    waitForContinue();
}

int main() {

    // Original
    // double c = 0;
    // Not necessary to give c a value at this point
    
    double c;

    // Original
    // Did not have variable to check whether input is above -273.15 degrees

    bool isValid = false;

    // Original
    // Did not declare the k value in advance
    // Not necessarily a problem, but also perhaps not a best practice

    double k;

    // Original
    // cin >> d;
    // d is not a declared variable

    // Clear the console

    clearConsole();

    // Original
    // Did not request input from the user

    cout << "Please provide the initial Celsius temperature (should be above -273.15 degrees)." << endl;

    // Original
    // Did not include method to repeatedly ask for input 

    while (true) {
        // Capture user input

        cout << "Celsius value to convert: ";
        cin >> c;

        // Original
        // Did not test for valid input

        // If input is invalid, repeat loop

        if (cin.fail()) {
           clearCin();
           cout << "You provided a non-double form of input. Please try again: ";
           waitForContinue();

        // If degrees are below threshold, call overloaded ctok function
        // Then repeat loop

        } else if (c < -273.15) {
           clearCin();
           ctok();   

        // If c value is appropriate, then clear the cin value
        // Convert c to k using ctok(c)
        // Print the report
        // And wait for user to read the result

        } else if (c > -273.16) {
            clearCin();
            k = ctok(c); 
            cout << "The Kelvin equivalent value is: " << k << endl;
            waitForContinue();
        }

        // Ensure console is clear before repeating loop
        clearConsole();
    }

    // Original
    // The "return 0" aspect was left off

    return 0;
}

