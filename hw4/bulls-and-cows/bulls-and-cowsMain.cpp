/**
 * bulls-and-cows.cpp
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

// #include "bulls-and-cows.hpp"

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

void waitForContinue(); 
void clearConsole();
void calculateRes(string &pattern, string &userInput, int &bulls, int &cows); 
void setPattern(string &pattern);
bool testUserInput(string &userInput);

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

// Wait 
void waitForContinue() {

    cout << endl << "Press enter to continue...";
    getchar();
}

void calculateRes(string &pattern, string &userInput, int &bulls, int &cows) { 
    string cowCounted = "OOOO";
     
    string copyPattern = pattern;
    bool found = true;
    int i {0};
    while(found && i < 4) {
        unsigned int exists = copyPattern.find(userInput[i]);
        if ((userInput[i] != pattern[i]) && exists >= 0 && exists < 4) {
            cout << "Cow: " << userInput[i] << copyPattern[exists] << endl;
            cows++;
            unsigned int locBull = pattern.find(userInput[i]);
            cowCounted[locBull] = 'X';
            copyPattern.erase(exists, 1);
        }
        i++;
    }
    
    for (size_t i {0}; i < 4; i++) {
        if (userInput[i] == pattern[i]) {
            cout << "Bull: " << userInput[i] << " " << pattern[i] << endl;
            bulls++;
            cout << "cowCounted: " << cowCounted << endl;
            if (cowCounted[i] == 'X') {
                cout << "Caught a cow" << endl;
                cows--;
            }
        } 
    } 

}

void setPattern(string &pattern) {
    vector<int> ran_nums;
    srand (time(NULL));
    
    for (int i {0}; i < 4; i++) {
        int temp = rand() % 10;
        ran_nums.push_back(temp);
    }

    
    for (size_t i {0}; i < ran_nums.size(); i++) {
        stringstream ss;
        ss << ran_nums.at(i); 
        pattern = pattern + ss.str();
    } 
    cout << "Pattern: " << pattern;
}
