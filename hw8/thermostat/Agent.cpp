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

// Default Agent Constructor
Agent::Agent()
    :
       _currentTemp(75),
       _heater(false), 
       _shouldSwitch(false),
       _switched(false)
{ }

// Inform the agent of the user's desired temperature
void Agent::setDesired(userInput) {
    _desired = userInput;
};

// Agent gathers precepts from the environment's state
void Agent::perceive(Environment& env) { 
    _heater = env.getHeater();
    _currentTemp = env.getTemp(); 
};

// Agent makes decisions about its next action
void Agent::think(bool& calibrated) { 

    // Set the range for the heater, in which it won't worry about temperature
    // changes
    int minBelow = 15;
    int minAbove = 5;

    // Whenever the desired and actual temperatures meet, make sure the machine
    // is indicated as having calibrated, and that it's available to switch on
    // or off again
    if (_currentTemp == _desired) {
        calibrated = true;
        switched = false;
    }
    
    // If the machine has not yet calibrated, and is not yet attempting to, and
    // the current temperature is at least 15 below the desired temp, prepare
    // to switch
    if (!calibrated && !_switched && _currentTemp <= _desired - minBelow) {
        _shouldSwitch = true;

    // If the machine has been calibrated at least once, and the machine has
    // not yet sought to get to the desired temperature, and the current
    // temperature is out of the range
    } else if (
            calibrated 
            &&
            !switched
            &&
            (_currentTemp <= _desired - minBelow 
            || _currentTemp >= _desired + minAbove)
            )
        _shouldSwitch = true;
};

void Agent::act(Environment& env); {
    if (_shouldSwitch) {
        env.switchHeater();
        _shouldSwitch = false;
        _switched = true;
    }
};

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
};

int Environment::getTemp() {
    return _temp;
};

bool Environment::getHeater() {
    return _heater;
};

void Simulator::askOwner(bool& isFinished, Agent& agt, Environment& env) {

    cout << "The current temperature is: ";
    cout << env.getTemp() << endl;

    cout << "The heater is: ";
    if (env.getHeater())
        cout << "On" << endl;
    else
        cout << "Off" << endl;

    int userInput;
    capture_user_input(userInput);

    if (userInput < -273)
        isFinished = true;

    agt.setDesired(userInput);
};

// Clear the console
void clearConsole() {

    // Clear the console
    cout << "\033[2J\033[1;1H";
}

// Wait for user response
void waitForContinue() {
    cout << endl << "Press enter to continue...";
    getchar();
}

// Capture the user input
void capture_user_input(int& userInput) {

	// Assume user input is invalid until proven otherwise
	bool valid_input = false;

	// Initiate endless loop to wait for valid response
	while (!valid_input) {

		// Receive user input as a string
		string user_input_temp;
        cout << endl;
		cout << "Please indicate the desired temperature (celsius)." << endl;
        cout << "(To stop the program, enter a value less than absolute zero (-274 or below))" << endl;

		getline(cin, user_input_temp);

		// Test if the user input is valid, and convert to an integer
		valid_input = testUserInput(user_input_temp, userInput);

		// If invalid, replay the while loop
		if (!valid_input) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << "Please try again" << endl;
		} 
        
        // Removing the below as I believe valid_input is already set
        // else {
			// End the while loop, if valid
		// 	valid_input = true;
		// }

		// Add formatting
		cout << endl;
	}
}

// Test whether the user's integer input is a valid response
bool testUserInput(string& user_input_temp, int& userInput) {

    // Assume user input is valid
    bool res = true;

    // Use a istringstream to convert user input to an integer within the appropriate range
    istringstream iss (user_input_temp);
    iss >> userInput;

    // If the string is not a valid reponse, return false and repeat loop
    if (iss.fail()) {
	res = false;
    }    

    // Return the result
    return res;
}

