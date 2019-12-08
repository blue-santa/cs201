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
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h> 
#include <utility>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::map;
using std::pair;
using std::make_pair;
using std::left;
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

