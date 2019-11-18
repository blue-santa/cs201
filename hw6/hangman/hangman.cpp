/*
 * hangman.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Function definition file for hangman project in hw6
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

// Clear the console
void clearConsole() {

	cout << "\033[2J\033[1;1H";
}

// Print the user's current progress towards the final sentence
bool printCurrentProgress(vector<pair<char, bool>> &quoteStatus, bool &isFinished) { 
	
	// Assume the user is finished
	isFinished = true;

	// Print the title of the progress to the console
	cout << "Current Progress:" << endl;

	// Initialize the final output as an empty string
	string output = "";

	// Iterate through each element of the quote
	for_each(quoteStatus.begin(), quoteStatus.end(), [&output, &isFinished](const auto &n){
		// If this element's pair has a second value of true, add this value to the final output
		if (n.second) {
			output = output + n.first;
		// If this element's pair's second value is false, add an underscore, to hide the missing value
		// Set isFinished to false, so that the game continues
		} else {
			isFinished = false;
			output = output + "_";
		}
	}); 

	// Print the output string to the console
	cout << output << endl << endl; 

	// Return the user's isFinished state
	return isFinished;
}

// Print the current state of the hanged man's captured body parts to the console
bool printCurrentHangmanState(vector<pair<string, bool>> &hangmanState, bool &isFinished, int &turns) {

	cout << "The hangedman's state of affairs: " << endl << endl;

	// Iterate through the list of hangman body parts
	// If the second value is marked as captured, print this part to the console
	for_each(hangmanState.begin(), hangmanState.end(), [](auto &n) {
		if (n.second) {
			cout << setw(15) << left << n.first << endl;
		}		
	});

	// Indicate the number of mistakes, out of ten total allowed
	cout << "Mistakes: " << turns << "/10" << endl << endl;

	// If the user has made 10 mistakes, the game is over
	// Switch isFinished to true
	if (turns == 10)
		isFinished = true;

	// Return user's isFinished state
	return isFinished;
}

// Update achieved progress on the intended sentence
bool updateProgress(char &nextGuess, int &turns, vector<pair<char, bool>> &quoteStatus, bool &charFound) {
	// Iterate through each element of the intended sentence
	// If the user's guess matches the element and this element is not already marked as visible
	// Switch the element to visible by changed the second value of the element pair to true
	// Also, indicate that the user successfully found a new character
	for_each(quoteStatus.begin(), quoteStatus.end(), [&nextGuess, &charFound](auto &n) {
			if (n.first == nextGuess && n.second == false) {
				charFound = true;
				n.second = true;
			} 
	}); 

	// If the user did not find a new character
	// Increase the available mistakes (turns) allowed
	if (!charFound) 
		turns++;

	// Return whether or not the user found a new character
	return charFound;
}

// Update the state of the current captured hangman body parts
void updateHangmanState(vector<pair<string, bool>> &hangmanState, bool &charFound) {

	// Initiate set value to false
	bool set = false;

	// Iterate through the list of body parts
	// If the user did not find a new character
	// And if this body part is the first in the list that is still marked as hidden
	// Switch this body part to visible
	// And change the set value to true, to prevent other body parts from becoming visible
	for_each(hangmanState.begin(), hangmanState.end(), [&set, &charFound](auto &n) {
			if (!(n.second) && !set && !charFound) {
				n.second = true; 
				set = true;
			}

	});
}

// Print state to screen, prompt the user to provide new input, and then proceed through list of update functions based on input
bool promptUserInput(vector<pair<char, bool>> &quoteStatus, vector<pair<string, bool>> &hangmanState, bool &isFinished, int &turns, bool &charFound) {

	clearConsole(); 

	// Print the current progress to the screen
	// And test if the user is successfully finished
	printCurrentProgress(quoteStatus, isFinished);

	// If the user is successfully finished
	// Congratulate the user and end the program
	if (isFinished) {
		cout << endl << "You win. Congrats!" << endl;
		return isFinished;
	} 

	// Print the current hanged man's state to the console
	// And test if the entire body is captured
	printCurrentHangmanState(hangmanState, isFinished, turns);

	// If the hanged man's entire body is captured
	// Inform the user and end the game
	if (isFinished) {
		cout << "You lose. Try again!" << endl;
		return isFinished;
	}

	// Prompt the user to provide a new character
	cout << "Please provide your next guess as a single character: ";

	// Declare variables to capture the next guess
	string temp;
	string temp_two;
	char nextGuess;

	// Capture the next guess
	getline(cin, temp); 
	istringstream instream(temp);
	if (!instream)
		return isFinished;
	instream >> temp_two; 
	nextGuess = temp_two[0];
	
	// Initialize the charFound variable for testing whether the user found a new character
	charFound = false;

	// Test whether the user found a new character
	charFound = updateProgress(nextGuess, turns, quoteStatus, charFound);

	// Update the state of the hanged man, based on the user's rate of success
	updateHangmanState(hangmanState, charFound);

	// Return whether or not the user is finished with the game, win or loss
	return isFinished; 
}
