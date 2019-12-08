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
        int _desired; 
        int _currentTemp;
        bool _heater;

    public:

        Agent()
           : _desired(75), _heater(false), _currentTemp(75) { 

        }

        void setDesired(userInput) {
            _desired = userInput;
        }

        void perceive(Environment& env) {

            _heater = env.getHeater();


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
            _heater = !_heater;
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
        void askOwner(bool& isFinished, Agent& agt) {

            int userInput;
            capture_user_input(userInput);

            if (userInput < -273)
                isFinished = true;

            agt.setDesired(userInput);
        } 
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

int main() { 

    // Inform user of the nature of the software 
    clearConsole(); 
    cout << "Welcome to the Temperature Simulator" << endl;
    cout << "\nPress any key to instruct the simulator to create an environment" << endl;
    waitForContinue();

    // Create initial environment, iteration, and quit vars 
    Environment env; 
    Agent agt;
    Simulator sim;
    int iter = 0;
    bool isFinished = false;

    clearConsole();
    cout << "Environment created" << endl;
    waitForContinue();

    // The temperature is going to go to zero, but slowly, unless you set the
    // temperature correctly, or something

    // Initiate while loop

    while (!isFinished) { 
        // Affect the environment
        env.iteration();

        // The agent senses the environment's temperature
        agt.perceive(env);

        // Agent requests current state from environment

        // Agent does whatever it does automatically before asking user for input

        // If iteration is divisible by 10, Agent requests user input
        // Test whether user wants to quit

        if (iter % 10 == 0) {
            sim.askOwner(isFinished, agt);
        }

        if (isFinished)
            break;

        // Agent sends actions that affect the environment

        // Increase iteration count
        iter++;
    }


    return 0; 
}


