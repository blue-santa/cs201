/**
 * boxer.cpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * The main file for the boxer program
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

int main (int argc, char **argv) { 

    // Declare variables to hold all user input and looping points

    string phrase;
    int layers;
    bool contLoop = true;

    // Initiate endless while loop that continues until user exits program

    while (contLoop) {

        // Ensure console is clear

        clearConsole(); 

        // Request the user to input the desired number of layers for the box

        requestLayers(layers, contLoop); 

        // If the user has not indicated a desire to quit the program, continue with the box-printing process

        if (contLoop) {
            
            // Request a phrase from the user for the box

            requestPhrase(phrase);

            // Print the box

            printBox(layers, phrase);

            // Wait for the user to indicate they are ready to continue

            waitForContinue();
        } else {

            // If the user has indicated a desire to stop, end the while loop

            break;
        } 
    } 

    return 0;
}
