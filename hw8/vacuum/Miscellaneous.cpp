/*
 * Miscellaneous.cpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Miscellaneous content definition file
 */

#include "Miscellaneous.hpp"
#include "Agent.hpp"
#include "Environment.hpp"

#include <iostream> 
#include <iomanip> 
#include <random> 
#include <cmath> 
#include <stdlib.h> 

using std::vector; 
using std::cout; 
using std::cin; 
using std::endl; 
using std::mt19937; 

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

// Print environment's current state
void printState(Environment& env, Agent& agt) {

    // Print room status
    cout << "Current status of each room:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "Room " << i + 1 << ": ";

        bool val = env.getRoom(i);
        if (val)
            cout << "dirty" << endl;
        else 
            cout << "clean" << endl;
    }
    cout << endl;

    // Vacuum status
    cout << "Vacuum status: " << endl;

    int currR = agt.getCurrRoom();
    cout << "Room: " << currR << endl;
    cout << "Action: ";

    int act = agt.getAction();
    if (act == 0) {
        cout << "Clean";
    } else {
        cout << "Move";
    }

}

// Return a random value according to a normal distribution
bool rollBool(mt19937* e1) {
    // Declare endpoints of the range for the distributions 
    int firs = 0; 
    int last = 16; 
    bool val = false;

	std::normal_distribution<> normal_dist(8, 4), min(firs), max(last);
	int res = normal_dist(*e1);
    if (res > 15) {
        val = true;
    }
	return val;
}
