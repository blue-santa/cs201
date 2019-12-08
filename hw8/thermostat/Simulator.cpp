/*
 * Agent.cpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Agent definition file
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "Agent.hpp"
#include "Miscellaneous.hpp"
#include "Environment.hpp"
#include "Simulator.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

// Request input from the owner
void Simulator::askOwner(bool& isFinished, Agent& agt, Environment& env) {

    // Inform the user of the environment's current state
    cout << "The current temperature is: ";
    cout << env.getTemp() << endl;

    cout << "The heater is: ";
    if (env.getHeater())
        cout << "On" << endl;
    else
        cout << "Off" << endl;

    // Capture the user's input
    int userInput;
    capture_user_input(userInput);

    // If the user has set an impossibly low value, end the program
    if (userInput < -273)
        isFinished = true;

    // Inform the agent of the user's desired temperature
    agt.setDesired(userInput);
}

