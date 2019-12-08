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

void Simulator::askOwner(bool& isFinished, Agent& agt, Environment& env) {

    cout << "The current temperature is: ";
    cout << env.getTemp() << endl;

    cout << "The heater is: ";
    if (env.getHeater())
        cout << "On" << endl;
    else
        cout << "Off" << endl;

    int userInput;
    capture_user_input(userInput);

    if (userInput < -273)
        isFinished = true;

    agt.setDesired(userInput);
}

