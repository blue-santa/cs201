/**
 * bulls-and-cowsMain.cpp
 * CS 201
 * Bryan Beus
 * October 15, 2019
 * The main file for bulls-and-cows
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>
#include <stdlib.h>

#include "bulls-and-cows.hpp"

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

int main(int argc, char **argv) {

    // Clear the console
    clearConsole();

    // Initiate a string to hold the correct pattern
    string pattern = "";
    
    // Call the setPattern function to set the pattern
    setPattern(pattern);

    // Initiate endless while loop to repeat until user makes a correct guess
    while (true) {

        // Print the main user prompt
        cout << endl;
        cout << endl;
        cout << "Enter four integers to guess the correct pattern" << endl;
        cout << endl;

        // Initiate the bulls and cows variables for this round
        int bulls = 0;
        int cows = 0; 

        // Collect user input
        string userInput;
        getline(cin, userInput); 

        // Ensure that user input is valid
        bool isValid = testUserInput(userInput);

        // If the input is not valid, restart loop
        if (!cin || cin.fail() || !isValid) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Please enter four integers: ";
            continue;
        }

        // Calculate the number of bulls and cows in the user input
        calculateRes(pattern, userInput, bulls, cows);

        // Report the number of bulls and cows
        cout << bulls << " bulls and " << cows << "cows" << endl;

        // If the user guessed correctly, end the program
        if (bulls == 4) {
            cout << "Congrats, you win!" << endl;
            waitForContinue();
            break;
        }
    }

	return 0;
}
