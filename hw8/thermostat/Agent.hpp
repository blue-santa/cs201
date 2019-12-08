/*
 * Agent.hpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Declaration file for Agent class
 */

#ifndef AGENT_HPP
#define AGENT_HPP

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

class Environment;

class Agent {

    private:

        // Member Variables
        int _desired;
        int _currentTemp;
        bool _heater;
        bool _shouldSwitch;
        bool _switched;

    public:

        // Constructor
        Agent();

        // Member Functions
        void setDesired(int& userInput);
        void perceive(Environment& env);
        void think(bool& calibrated);
        void act(Environment& env);
};

#endif
