/**
 * boxerprint.cpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * The function declaration file for the main boxer.cpp project
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "boxer.hpp"

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

// Print a line of asterixs of the appropriate length for the box

void printFull(int layers, size_t phraseLength) {
    for (int i {0}; i < layers; i++) {
        cout << string(layers, '*') << string(phraseLength + 2, '*') << string(layers, '*') << endl;
    }
}

// Print a line of asterixs and empty spaces as padding around the phrase

void printEmpty(int layers, size_t phraseLength) {
    cout << string(layers, '*') << string(phraseLength + 2, ' ') << string(layers, '*') << endl;
}

// The main program for printing the phrase

void printBox(int layers, string & phrase) {

    // Clear the console

    clearConsole();

    // Declare a variable to hold the size of the phrase length

    size_t phraseLength = phrase.length();

    // Print the sides of the box before the middle line

    printFull(layers, phraseLength);
    printEmpty(layers, phraseLength);

    // Print the middle line of the box

    cout << string(layers, '*') << " " << phrase << " " << string(layers, '*') << endl;
    
    // Print the sides of the box that come after the middle line

    printEmpty(layers, phraseLength);
    printFull(layers, phraseLength);

}

// Request a phrase from the user

void requestPhrase(string & phrase) { 

    // Prompt the user

    cout << "\nPlease enter the phrase to place inside the box." << endl;

    // Ensure the cin buffer is clear

    clearCin();

    // Initiate endless while loop that continues until user inputs proper response

    while (true) {

        // Request input phrase from the user

        getline(cin, phrase);

        // Test that the phrase is valid
        // If not, repeat while loop

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please provide a valid input. (This should be a sentence.)" << endl;
        } else {

            // End loop, if input is valid
            break;
        }
    }
}

// Request the number of layers from the user

void requestLayers(int & layers, bool & contLoop) {

    // Prompt the user

    cout << "How many layers? (To quit the program, enter a non-integer value, such as a character.) " << endl;

    // Initiate endless while loop that continues until user provides valid input

    while (true) {

        // Input user value

        cin >> layers;

        // Test if user value is valid
        // If not, assume user is attempting to quit program

        if (cin.fail()) {
           clearCin();
           contLoop = false; 
           break;

        // If the user's input is valid, but less than 1, repeat loop

        } else if (layers < 1) {
            clearCin();
            cout << "Please provide an integer that is greater in value than zero." << endl;        

        // If user's input is fully valid, end loop

        } else { 
            break; 
        }
    } 
}
