/**
 * bulls-and-cows.cpp
 * CS 201
 * Bryan Beus
 * October 14, 2019
 * The function definition file
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

// Test whether the user's input is a valid response
bool testUserInput(string &userInput) {

    // Assume user input is valid
    bool res = true;

    // Use a istringstream to convert user input to an integer within the appropriate range
    int testVal; 
    istringstream iss (userInput); 
    iss >> testVal;

    // If the string is not a valid reponse, return false
    if (iss.fail())
        res = false;

    // If the user entered an integer that cannot be converted to a proper integer, end the program
    if (testVal > 10000 || testVal < 0)
        res = false;

    // Return the result
    return res;
}

// Clear the console 
void clearConsole() { 

    // Clear the console 
    cout << "\033[2J\033[1;1H"; 
}

// Wait for user response
void waitForContinue() { 
    cout << endl << "Press enter to continue...";
    getchar();
}

// Calculate the number of bulls and cows in the user's response
void calculateRes(string &pattern, string &userInput, int &bulls, int &cows) { 

    // Initiate a string to track any occurrences of a cow
    // This allows us to remove the cows later, should they turn out to be a bull
    string cowCounted = "OOOO";
     
    // Create a copy of the pattern, so that we can remove cows from the copied pattern any time they are found
    // Initiate endless while loop to test for cows
    string copyPattern = pattern;
    bool found = true;
    int i {0};
    while(found && i < 4) {
        
        // Check to see if the current userInput character is in the copy pattern
        unsigned int exists = copyPattern.find(userInput[i]);

        // Test that this is not a bull
        if ((userInput[i] != pattern[i]) && exists >= 0 && exists < 4) {
            // If this is a proper cow, increase the cow count
            cows++;

            // Adapt the cowCounted variable to indicate where this cow would be, in case the user
            // provides a bull value at that integer
            unsigned int locBull = pattern.find(userInput[i]); 
            cowCounted[locBull] = 'X';

            // Erase the value from the copy pattern, so that we cannot get this twice
            copyPattern.erase(exists, 1);
        }

        // Increase current iteration i
        i++;
    }
    
    // Test for bulls
    for (size_t i {0}; i < 4; i++) {
        if (userInput[i] == pattern[i]) {
            // If this is a proper bull, increase bull count
            bulls++;

            // Check to see if this was earlier counted as a cow
            // If so, reduce cow count
            if (cowCounted[i] == 'X') {
                cows--;
            }
        } 
    } 

}

// Set the pattern which the user must guess
void setPattern(string &pattern) {

    // Create a vector of four random integers
    vector<int> ran_nums;
    srand (time(NULL));
    
    for (int i {0}; i < 4; i++) {
        int temp = rand() % 10;
        ran_nums.push_back(temp);
    }

    // Convert the integers into a string, for ease in testing
    for (size_t i {0}; i < ran_nums.size(); i++) {
        stringstream ss;
        ss << ran_nums.at(i); 
        pattern = pattern + ss.str();
    } 
}
