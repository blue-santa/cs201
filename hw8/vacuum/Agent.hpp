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

using std::cout;
using std::cin;
using std::endl;

class Environment;

class Agent {

    private:

        // Member Variables
        int _currRoom;
        int _nextAction;
        int _moveVal;
        bool _roomDirty;

    public:

        // Constructor
        Agent();

        // Member Functions
        void perceive(Environment& env);
        void think();
        void act(Environment& env);
        int getAction();
        int getCurrRoom();
};

#endif
