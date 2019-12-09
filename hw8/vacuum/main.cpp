/*
 * main.cpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Main file for vacuum project in hw8
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

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

	// Create pseudo-random device
	std::random_device r; 
	std::seed_seq seedObj{r(), r(), r(), r(), r(), r(), r(), r()};
	mt19937 e1(seedObj);

    // Inform user of the nature of the software 
    clearConsole(); 
    cout << "Welcome to the Vacuum Simulator" << endl;
    cout << "\nThe simulator will now create an environment" << endl;
    waitForContinue();

    // Create initial environment, iteration, and quit vars 
    clearConsole();
    Environment env(e1); 
    Agent agt;
    Simulator sim;
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
        agt.think();
        agt.act(env);

        printState(env);

        sim.askOwner();
    } 

    return 0; 
}


