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
#include <random>
#include <cmath>
#include <stdlib.h> 

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::mt19937;

class Environment {

    private:

        // Member Variables 
        vector<bool> _rooms;
        mt19937 *_e1;

    public:

        // Constructors
        Environment(mt19937& e1);

        // Member Functions
        void cleanRoom(int& roomIndex);
        void iteration();
        bool getRoom(int& roomIndex);

};

#endif

