/**
 * quadratic.cpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * A program to calculate a quadratic equation
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

// Request values from the user for the quadratic equation

void getValues(vector<double> &vars) {

    // Declare user input variable 

    double userInput;

    // Initiate a for loop to repeat the request for each of the values a, b, c 

    for (int i {0}; i < 3; i++) {

        // Initiate endless while loop to await a valid user input for current variable

        while (true) {

            // Test which value i to determin which "abc" value we are requesting

            if (i == 0) {
                cout << "a: ";
            } else if (i == 1) {
                cout << "b: ";
            } else if (i == 2) {
                cout << "c: ";
            }

            // Retrieve userInput

            cin >> userInput;

            // If user input is avlid, repeat

            if (cin.fail()) {
                clearCin();
                cout << "Provided input is not valid. Please try again." << endl;

            // If we are finding the value for "a" and the user input "0", repeat

            } else if (i == 0 && userInput == 0) {
                clearCin();
                cout << "The value of \"a\" should be non-zero. Please try again." << endl;

            // Otherwise, add this to our total variables and move to next value i
            } else {
                vars.push_back(userInput);
                break;
            } 
        }
    } 
}

bool checkSquareRoot(vector<double> vars) {

    // Declare variable to test whether user input can provide valid result

    bool isValid = false;

    // For ease of programming, convert vector to variables a, b, c

    double a = vars.at(0);
    double b = vars.at(1);
    double c = vars.at(2);

    // Test that value under square root is non-imaginary 
    // If we can find a valid result, change isValid to true

    if (!((b * b - 4 * a * c) < 0)) {
        isValid = true;
    } 
    
    // Return resulting bool value

    return isValid;
}

// Find the roots of the equation

vector<double> findRoots(vector<double> vars) {

    // Declare results variable to store our roots

    vector<double> results;

    // For ease of programming, convert vector values to values a, b, c

    double a = vars.at(0);
    double b = vars.at(1);
    double c = vars.at(2);

    // Calculate the first root

    double firstRoot = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);

    // Calculate the second root

    double secondRoot = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);

    // Add the results to our final vector

    results.push_back(firstRoot);
    results.push_back(secondRoot);

    // Return our results
    
    return results;
}

// Print the results of our calculations

void printResults (vector<double> & results) {

    cout << "The roots of the equation are: " << results.at(0) << " and " << results.at(1) << endl; 

}

int main() {

    // Declare the abc values as doubles

    vector<double> vars;

    // Declare the value to verify that all provided values produce a valid response, considering square root in formula

    bool isValid = false;

    // Declare vector to hold resulting "x" values

    vector<double> results;

    // Ensure the console is clear

    clearConsole();

    // Prompt the user

    cout << "Please provide the values of the constants for the equation. Value \"a\" should be non-zero." << endl;
    
    // Request user values
    getValues(vars);

    // Check that we have a valid equation

    isValid = checkSquareRoot(vars);

    // If the quadratic equation is valid, assemble the roots

    if (isValid) {
        results = findRoots(vars);

    // If the quadratic equation is not valid, inform the user of the issue

    } else {
        cout << "The value of \"b^2 - 4a\" is not positive, and therefore this quadratic equation will not work." << endl;
    }

    if (results.size()) {
        printResults(results);
    }

    return 0;
}

