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

bool printCurrentProgress(vector<pair<char, bool>> &quoteStatus, bool &isFinished) { 
	isFinished = true;

	cout << "Current Progress:" << endl;

	string output = "";

	for_each(quoteStatus.begin(), quoteStatus.end(), [&output, &isFinished](const auto &n){
		if (n.second) {
			output = output + n.first;
		} else {
			isFinished = false;
			output = output + "_";
		}
	}); 

	cout << output << endl << endl; 

	return isFinished;
}

bool printCurrentHangmanState(vector<pair<string, bool>> &hangmanState, bool &isFinished, int &turns) {

	cout << "The hangedman's state of affairs: " << endl << endl;

	for_each(hangmanState.begin(), hangmanState.end(), [](auto &n) {
		if (n.second) {
			cout << setw(15) << left << n.first << endl;
		}		
	});

	cout << "Mistakes: " << turns << "/10" << endl << endl;

	if (turns == 10)
		isFinished = true;

	return isFinished;
}

bool updateProgress(char &nextGuess, int &turns, vector<pair<char, bool>> &quoteStatus, bool &charFound) {
	for_each(quoteStatus.begin(), quoteStatus.end(), [&nextGuess, &charFound](auto &n) {
			if (n.first == nextGuess && n.second == false) {
				charFound = true;
				n.second = true;
			} 
	}); 

	if (!charFound) 
		turns++;

	return charFound;
}

void updateHangmanState(vector<pair<string, bool>> &hangmanState, bool &charFound) {
	bool set = false;
	for_each(hangmanState.begin(), hangmanState.end(), [&set, &charFound](auto &n) {
			if (!(n.second) && !set && !charFound) {
				n.second = true; 
				set = true;
			}

	});
}

bool promptUserInput(vector<pair<char, bool>> &quoteStatus, vector<pair<string, bool>> &hangmanState, bool &isFinished, int &turns, bool &charFound) {

	clearConsole();

	printCurrentProgress(quoteStatus, isFinished);

	if (isFinished) {
		cout << endl << "You win. Congrats!" << endl;
		return isFinished;
	} 

	printCurrentHangmanState(hangmanState, isFinished, turns);

	if (isFinished) {
		cout << "You lose. Try again!" << endl;
		return isFinished;
	}

	cout << "Please provide your next guess as a single character: ";

	string temp;
	string temp_two;
	char nextGuess;

	getline(cin, temp); 
	istringstream instream(temp);
	if (!instream)
		return isFinished;
	instream >> temp_two; 
	nextGuess = temp_two[0];
	
	charFound = false;
	charFound = updateProgress(nextGuess, turns, quoteStatus, charFound);
	updateHangmanState(hangmanState, charFound);

	return isFinished; 
}
