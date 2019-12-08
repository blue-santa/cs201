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
#include "Environment.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

// Default Agent Constructor
Agent::Agent()
    :
       _currentTemp(75),
       _heater(false), 
       _shouldSwitch(false),
       _switched(false)
{ }

// Inform the agent of the user's desired temperature
void Agent::setDesired(int& userInput) {
    _desired = userInput;
}

// Agent gathers precepts from the environment's state
void Agent::perceive(Environment& env) { 
    _heater = env.getHeater();
    _currentTemp = env.getTemp(); 
}

// Agent makes decisions about its next action
void Agent::think(bool& calibrated) { 

    // Set the range for the heater, in which it won't worry about temperature
    // changes
    int minBelow = 15;
    int minAbove = 5;

    // Whenever the desired and actual temperatures meet, make sure the machine
    // is indicated as having calibrated, and that it's available to switch on
    // or off again
    if (_currentTemp == _desired) {
        calibrated = true;
        _switched = false;
    }
    
    // If the machine has not yet calibrated, and is not yet attempting to, and
    // the current temperature is at least 15 below the desired temp, prepare
    // to switch
    if (!calibrated && !_switched && _currentTemp <= _desired - minBelow) {
        _shouldSwitch = true;

    // If the machine has been calibrated at least once, and the machine has
    // not yet sought to get to the desired temperature, and the current
    // temperature is out of the range
    } else if (
            calibrated 
            &&
            !_switched
            &&
            (_currentTemp <= _desired - minBelow 
            || _currentTemp >= _desired + minAbove)
            )
        _shouldSwitch = true;
}

void Agent::act(Environment& env) {
    if (_shouldSwitch) {
        env.switchHeater();
        _shouldSwitch = false;
        _switched = true;
    }
}

