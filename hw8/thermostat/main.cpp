/*
 * main.cpp
 * CS 201
 * December 6, 2019
 * Bryan Beus
 * Main file for themostat main project in hw8
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

Class Agent {

    private: 
        _desired; 
        _heater;

    public:

        Agent()
           : _desired(75), _heater(false) { 

        }

        void perceive(Environment) {

            _heater = Environment.getHeater();

        }

        void think() {

        }

        void act(Environment); {

        }

};

Class Environment { 

    private:
        int _temp;
        bool _heater = false; 

    public: 

        Environment()
            : _temp(45), _heater(false) {}

        Environment(int Temp, bool Heater) {
            _temp = Temp;
            _heater = Heater;
        }


        void switchHeater() {
            _heater = !_hejater;
        }

        void iteration() { 
            if (_heater) { 
                ++_temp;
            } else {
                --_temp;
            }
        }

        int getTemp() {
            return _temp;
        }

        bool getHeater() {
            return _heater;
        } 
};

Class Simulator() {

    public:
        void askOwner() {

            string temp;

            while (true) {
                getline(cin, temp); 
                if (!cin) { 

                }
            }


        }

};

int main() {

    // Create initial environment

    // Set iteration var

    // Inform user of the nature of the software
    // The temperature is going to go to zero, but slowly, unless you set the
    // temperature correctly, or something

    // Initiate while loop
    //
    // Simulator runs through iteration, affecting the environment
    //
    // The environment sends the agent percepts
    //
    // Agent requests current state from environment
    //
    // Agent does whatever it does automatically before asking user for input
    //
    // If iteration is divisible by 10, Agent requests user input
    // Test whether user wants to quit
    //
    // Agent sends actions that affect the environment

    return 0; 
}


