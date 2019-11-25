/*
 * caesar_cypher.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Function definition file for caesar_cypher project in hw7
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <map>

#include "caesar_cypher.hpp"

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::make_pair;
using std::for_each;
using std::getline;
using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::find;
using std::map;
using std::setw;
using std::left;

// Capture the user's input - string version
void capture_user_input_string(string& user_input, bool& isFinished) {

	// Assume input is not true until proven
	bool valid_input = false;

	// Initiate endless while loop to accept user input until response is valid
	while (!valid_input) {

		// Prompt the user
		cout << "Enter a phrase to encrypt (blank to quit): ";
		getline(cin, user_input);

		// Test whether the user has indicated that they are finished
		valid_input = testUserInput_string(user_input, isFinished);

		// If input is invalid, restart (unused function)
		if (!valid_input) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << "Please try again" << endl;
		} else {

			// Cease while loop
			valid_input = true;
		}

		// Add formatting
		cout << endl;
	}
}

// Test whether the user's input is a valid response - string portion
bool testUserInput_string(string &userInput, bool& isFinished) {

    // Assume user input is valid
    bool res = true;

    // Use istringstream to test user input
    string test_blank;
    istringstream iss (userInput);
    iss >> test_blank;

    // If the user has entered a blank string, indicate in the isFinished bool variable
    if (test_blank == "") {
        isFinished = true;
    }

    // Return the result
    return res;
}

// Capture the user input -- shift amount portion
void capture_user_input_int(int& shift_amount) {
	
	// Assume user input is invalid until proven otherwise
	bool valid_input = false;

	// Initiate endless loop to wait for valid response
	while (!valid_input) {

		// Receive user input as a string
		string user_input;
		cout << "By how many digits would you like to encrypt the phrase? ";
		getline(cin, user_input);

		// Test if the user input is valid, and convert to an integer
		valid_input = testUserInput_int(user_input, shift_amount);

		// If invalid, replay the while loop
		if (!valid_input) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << "Please try again" << endl;
		} else {
			// End the while loop, if valid
			valid_input = true;
		}

		// Add formatting
		cout << endl;
	}
}

// Test whether the user's integer input is a valid response
bool testUserInput_int(string& userInput, int& shift_amount) {

    // Assume user input is valid
    bool res = true;

    // Use a istringstream to convert user input to an integer within the appropriate range
    int testVal;
    istringstream iss (userInput);
    iss >> testVal;

    // If the string is not a valid reponse, return false and repeat loop
    if (iss.fail()) {
	res = false;
    } else {
	    // If the string is a valid integer, set the shift_amount variable
	    shift_amount = testVal;
    }

    // Get rid of excess shift amount
    shift_amount = shift_amount % 26;

    // Return the result
    return res;
}

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

// Shift the user's message into the cypher version
void shift_message(string& user_input, int& shift_amount, string& res_str) {

	// Initiate two strings to track alphabetical position
	// One for upper and for lower
	string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lower = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

	// For each character in the user's message, do the following
	for (size_t i = 0; i < user_input.size(); i++) {

		// Obtain the character at this position i
		char temp = user_input.at(i); 
		string val(1, temp);

		// Test if the character is found in the uppercase options
		size_t upper_ind = upper.find(val);

		// Test if the character is found in the lowercase options
		size_t lower_ind = lower.find(val);

		// If found in the uppercase options
		if (upper_ind != std::string::npos) {
			
			// Set a new variable that is equal to the intended cypher amount
			temp = upper.at(upper_ind + 26 + shift_amount);
			string more(1, temp);

			// Add this to the final string to be returnec
			res_str = res_str + more;
		
		// If found in the lowercase options
		} else if (lower_ind != std::string::npos) {

			// Set a new variable that is equal to the intended cypher amount 
			temp = lower.at(lower_ind + 26 + shift_amount);
			string more(1, temp);

			// Add this to the final string to be returned
			res_str = res_str + more;
			
		// Otherwise, just add the character at this position to the final string to be returned
		} else { 
			res_str = res_str + val;
		}

	}

}

