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

Environment::Environment()
    : _temp(45), _heater(false) {};

Environment::Environment(int Temp, bool Heater) {
    _temp = Temp;
    _heater = Heater;
} 

void Environment::switchHeater() {
    _heater = !_heater;
}

void Environment::iteration() { 
    if (_heater) { 
        ++_temp;
    } else {
        --_temp;
    }
}

int Environment::getTemp() {
    return _temp;
}

bool Environment::getHeater() {
    return _heater;
}
