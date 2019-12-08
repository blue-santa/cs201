#ifndef AGENT_HPP
#define AGENT_HPP

/*
 * Agent.hpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Declaration file for Agent class
 */

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

class Agent {

    private:

        // Member Variables
        int _desired;
        int _currentTemp;
        bool _heater;
        bool _shouldSwitch;
        bool switched;

    public:

        // Constructor
        Agent();

        // Member Functions
        void setDesired(userInput);
        void perceive(Environment& env);
        void think(calibrated);
        void act(Environment& env);

};

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

class Simulator() {

    public:
        // Member Functions
        void askOwner(bool& isFinished, Agent& agt, Environment& env);

};

// Clear the console
void clearConsole();

// Wait for user response
void waitForContinue();

// Capture the user input
void capture_user_input(int& userInput);

// Test whether the user's integer input is a valid response
bool testUserInput(string& user_input_temp, int& userInput);

#endif
