/*
 * Environment.cpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Environment definition file
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

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

// Default constructor for Environment class
Environment::Environment()
    : _temp(45), _heater(false) {};

// Custom constructor for Environment class
Environment::Environment(int Temp, bool Heater) {
    _temp = Temp;
    _heater = Heater;
} 

// Switch the heater to the opposite boolean value
void Environment::switchHeater() {
    _heater = !_heater;
}

// Perform one iteration by adjusting heat either 1 or -1 value
void Environment::iteration() { 
    if (_heater) { 
        ++_temp;
    } else {
        --_temp;
    }
}

// Returns the current temperature
int Environment::getTemp() {
    return _temp;
}

// Returns a bool regarding whether the heater is on or off
bool Environment::getHeater() {
    return _heater;
}
