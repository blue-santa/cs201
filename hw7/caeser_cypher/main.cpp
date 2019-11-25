/*
 * main.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Main file for caesar cypher in hw7
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
using std::getline;

int main() {
	bool isFinished = false;
	clearConsole();

	while (!isFinished) {

		string user_input;
		int shift_amount;

		capture_user_input_string(user_input, isFinished);

		if (isFinished) {
			break;
		}

		capture_user_input_int(shift_amount); 

		string res_str;

		shift_message(user_input, shift_amount, res_str);

		cout << endl << "The new message is: " << res_str << endl << endl;

	} 

	// Print goodbye message
	cout << endl << "Program complete" << endl;

	return 0; 
}

void capture_user_input_string(string& user_input, bool& isFinished) {
	bool valid_input = false;
	while (!valid_input) {
		cout << "Enter a phrase to encrypt (blank to quit): ";
		getline(cin, user_input);

		valid_input = testUserInput_string(user_input, isFinished);

		if (!valid_input) {
			cin.clear();
			cin.ignore(1000, '\n'); 
			cout << endl;
			cout << "Please try again" << endl;
		} else {
			valid_input = true;
		} 
		 
		cout << endl; 
	}
}

// Test whether the user's input is a valid response
bool testUserInput_string(string &userInput, bool& isFinished) {

    // Assume user input is valid
    bool res = true;

    // Use a istringstream to convert user input to an integer within the appropriate range
    string test_blank;
    istringstream iss (userInput);
    iss >> test_blank;

    // If the string is not a valid reponse, return false
    if (test_blank == "") {
        isFinished = true;
    }

    // Return the result
    return res;
}

void capture_user_input_int(int& shift_amount) {
	bool valid_input = false;
	while (!valid_input) {
		string user_input;
		cout << "By how many digits would you like to encrypt the phrase? ";
		getline(cin, user_input);

		valid_input = testUserInput_int(user_input, shift_amount);

		if (!valid_input) {
			cin.clear();
			cin.ignore(1000, '\n'); 
			cout << endl;
			cout << "Please try again" << endl;
		} else {
			valid_input = true;
		} 
		 
		cout << endl; 
	}
}

// Test whether the user's input is a valid response
bool testUserInput_int(string& userInput, int& shift_amount) {

    // Assume user input is valid
    bool res = true;

    // Use a istringstream to convert user input to an integer within the appropriate range
    int testVal;
    istringstream iss (userInput);
    iss >> testVal;

    // If the string is not a valid reponse, return false
    if (iss.fail()) { 
	res = false;
    } else {
	    shift_amount = testVal;
    }

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

void shift_message(string& user_input, int& shift_amount, string& res_str) {

	string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lower = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

	for (size_t i = 0; i < user_input.size(); i++) {
		char temp = user_input.at(i);
		string val(1, temp);
		size_t upper_ind = upper.find(val);
		size_t lower_ind = lower.find(val);
		if (upper_ind != std::string::npos) { 
			temp = upper.at(upper_ind + 26 + shift_amount);
			string more(1, temp);
			res_str = res_str + more;
		} else if (lower_ind != std::string::npos) {
			temp = lower.at(lower_ind + 26 + shift_amount);
			string more(1, temp);
			res_str = res_str + more;
		} else {
			res_str = res_str + val;
		} 

	}

}
