/*
 * Environment.cpp
 * CS 201
 * December 8, 2019
 * Bryan Beus
 * Environment definition file
 */

#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <string> 
#include <map> 
#include <random> 
#include <cmath> 
#include <stdlib.h>

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

// Return a random value according to a normal distribution
int Environment::RandomBetweenN(int first, int last, mt19937 &e1) {
	std::normal_distribution<> normal_dist(8, 4), min(first), max(last);
	int val = normal_dist(e1);
	return val;
}

// Default constructor for Environment class
Environment::Environment(mt19937& e1) {
    for (int i = 0; i < 8; i++) {
        bool val = *this.rollRoom(e1);
        _rooms.push_back(val);        
    }
};

bool Environment::rollRoom(mt19937& e1) {
        
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
