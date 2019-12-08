/*
 * Environment.hpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Declaration file for Environment class
 */

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

class Environment {

    private:

        // Member Variables
        int _temp;
        bool _heater = false;

    public:

        // Constructors
        Environment();
        Environment(int Temp, bool Heater);

        // Member Functions
        void switchHeater();
        void iteration();
        int getTemp();
        bool getHeater();

};

#endif
