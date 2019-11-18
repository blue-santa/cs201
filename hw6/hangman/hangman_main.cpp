/*
 * hangman_main.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Main file for hangman project in hw6
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

#include "hangman.hpp"

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

int main() {

	// Initialize bool value to test whether user is finished with the game
	bool isFinished = false;

	// Initialize vector of body parts to capture for the hanged man
	vector<string> hangmanItems {"head", "body", "right arm", "left arm", "right hand", "left hand", "right leg", "left leg", "right foot", "left foot"}; 
	vector<pair<string, bool>> hangmanState;

	// For each body part, add an assumed value of "false" to indicate that the body part is not yet captured
	for_each(hangmanItems.begin(), hangmanItems.end(), [&hangmanState](string item) { 
			hangmanState.push_back(make_pair(item, false));
	});

	// Initialize the quote for the game
	string quote = "Whenever people tell me that I will regret whatever I just did when tomorrow morning comes, I sleep in until noon the next day, because I am a problem solver.";

	// Initialize a vector to hold each element of the sentence to be guess
	vector<pair<char, bool>> quoteStatus;

	// For each element, pair it with a value of false to indicate that it should remain hidden
	for_each(quote.begin(), quote.end(), [&quoteStatus](char n) {
		bool statusBool = false;

		// Values that are not part of the guessing game, including periods, whitespaces, and commas, do not need to be hidden
		if (n == '.' || n == ' ' || n == ',') {
			statusBool = true;
		}
		quoteStatus.push_back(make_pair(n, statusBool)); 
	});

	// Initialize the number of turns (or mistakes) the user has made
	int turns = 0;

	// Initialize the variable to test whether the user has found a new variable
	// Assume true for now
	bool charFound = true;

	// Initiate while loop to continue game so long as user has neither won nor lost
	// Prompt user input for each turn of the game
	while (!isFinished) {
		isFinished = promptUserInput(quoteStatus, hangmanState, isFinished, turns, charFound); 
	}

	return 0; 
}
