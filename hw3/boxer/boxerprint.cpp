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

    std::cout << std::endl << "Press enter to continue...";
    getchar();
}

// Clear the console

void clearConsole() {

        // Clear the console

    std::cout << "\033[2J\033[1;1H";

}

void clearCin() {
    cin.clear();
    cin.ignore(1000, '\n'); 
}

void printFull(int layers, size_t phraseLength) {
    for (int i {0}; i < layers; i++) {
        cout << string(layers, '*') << string(phraseLength + 2, '*') << string(layers, '*') << endl;
    }
}

void printEmpty(int layers, size_t phraseLength) {
    cout << string(layers, '*') << string(phraseLength + 2, ' ') << string(layers, '*') << endl;
}

void printWord(int layers, string & phrase) {
    clearConsole();

    size_t phraseLength = phrase.length();

    printFull(layers, phraseLength);
    printEmpty(layers, phraseLength);

    cout << string(layers, '*') << " " << phrase << " " << string(layers, '*') << endl;
    
    printEmpty(layers, phraseLength);
    printFull(layers, phraseLength);

}

void requestPhrase(string & phrase) { 

    cout << "\nPlease enter the phrase to place inside the box." << endl;

    clearCin();

    while (true) {

        getline(cin, phrase);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please provide a valid input. (This should be a sentence.)" << endl;
        } else {
            break;
        }
    }
}

void requestLayers(int & layers, bool & contLoop) {
    cout << "How many layers? (To quit the program, enter a non-integer value, such as a character.) " << endl;

    while (true) {

        cin >> layers;

        if (cin.fail()) {
           clearCin();
           contLoop = false; 
           break;
        } else if (layers < 1) {
            clearCin();
            cout << "Please provide an integer that is greater in value than zero." << endl;        
        } else { 
            break; 
        }
    } 
}
