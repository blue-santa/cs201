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

	bool isFinished = false;

	vector<string> hangmanItems {"head", "body", "right arm", "left arm", "right hand", "left hand", "right leg", "left leg", "right foot", "left foot"};

	vector<pair<string, bool>> hangmanState;

	for_each(hangmanItems.begin(), hangmanItems.end(), [&hangmanState](string item) { 
			hangmanState.push_back(make_pair(item, false));
	});

	string quote = "Whenever people tell me that I will regret whatever I just did when tomorrow morning comes, I sleep in until noon the next day, because I am a problem solver.";

	vector<pair<char, bool>> quoteStatus;
	for_each(quote.begin(), quote.end(), [&quoteStatus](char n) {
		bool statusBool = false;
		if (n == '.' || n == ' ' || n == ',') {
			statusBool = true;
		}
		quoteStatus.push_back(make_pair(n, statusBool)); 
	});

	int turns = 0;
	bool charFound = true;

	while (!isFinished) {
		isFinished = promptUserInput(quoteStatus, hangmanState, isFinished, turns, charFound); 
	}

	return 0; 
}
