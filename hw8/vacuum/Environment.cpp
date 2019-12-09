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

// Default constructor for Environment class
Environment::Environment(mt19937& e1) {
    *_e1 = &e1;
    for (int i = 0; i < 8; i++) {
        bool val = rollBool(_e1);
        _rooms.push_back(val);        
    }
};

// Switch the heater to the opposite boolean value
void Environment::cleanRoom(int& roomIndex) {
    _rooms[roomIndex] = false;
}

// Perform one iteration by adjusting heat either 1 or -1 value
void Environment::iteration() { 
    for (int i = 0; i < 8; i++) {
        if (_rooms[i] == false) {
            _rooms[i] = rollBool(_e1);
        }
    }
}

// Returns the current temperature
bool Environment::getRoom(int& roomIndex) {
    return _rooms[roomIndex];
}

