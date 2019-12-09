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

using std::cout;
using std::cin;
using std::endl;

// Default Agent Constructor
Agent::Agent()
    :
        _currRoom(0),
        _nextAction(0),
        _moveVal(1)
{ }

// Agent gathers precepts from the environment's state
void Agent::perceive(Environment& env) { 
    _roomDirty = env.getRoom(_currRoom);
}

// Agent makes decisions about its next action
void Agent::think() { 

    if (_currRoom == 0)
        _moveVal = 1;
    else if (_currRoom == 7)
        _moveVal = -1;

    if (_roomDirty) {
        _nextAction = 0;
    } else {
        _nextAction = 1;
    }
}

// Switch the environment heater and reset the local switching variables
void Agent::act(Environment& env) {
    if (_nextAction == 0) {
        env.cleanRoom(_currRoom);
    } else {
        _currRoom += _moveVal;
    }
}

// Return the next action
int Agent::getAction() {
    return _nextAction;
}

// Return the current room
int Agent::getCurrRoom() {
    return _currRoom;
}
