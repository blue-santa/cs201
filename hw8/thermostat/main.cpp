/*
 * main.cpp
 * CS 201
 * December 6, 2019
 * Bryan Beus
 * Main file for themostat main project in hw8
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "Environment.hpp"
#include "Agent.hpp"
#include "Simulator.hpp"
#include "Miscellaneous.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

int main() { 

    // Inform user of the nature of the software 
    clearConsole(); 
    cout << "Welcome to the Temperature Simulator" << endl;
    cout << "\nThe simulator will now create an environment" << endl;
    waitForContinue();

    // Create initial environment, iteration, and quit vars 
    Environment env; 
    Agent agt;
    Simulator sim;
    bool calibrated = false;
    int iter = 0;
    bool isFinished = false;

    // Clear screen and print introduction to console
    clearConsole();
    cout << "Environment created" << endl;
    waitForContinue();

    // Initiate while loop 
    while (!isFinished) { 

        // Clear screen
        clearConsole();

        // Affect the environment
        env.iteration();

        // The agent performs its duties 
        agt.perceive(env);
        agt.think(calibrated);
        agt.act(env);

        // If iteration is divisible by 10, Agent requests user input
        // Test whether user wants to quit 
        if (iter % 10 == 0) {
            sim.askOwner(isFinished, agt, env);
        }

        if (isFinished)
            break;

        // Increase iteration count
        iter++;
    } 

    return 0; 
}


