/**
 * substrings.cpp
 * CS 201
 * Bryan Beus
 * October 4, 2019
 * The function definition file for substrings
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "substrings.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

void exercise1(string & input) {

	printShrinking(input);
}

void requestInput(string & input) {

	cout << "Please provide a string: ";

	while (true) {
		cin >> input;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Try again: "; 
		} else {
			break; 
		}

	}
}

void printShrinking(string & input) {

	for (size_t i {0}; i < input.length(); i++) {

		int currSize = input.length() - i;
		cout << input.substr(0, currSize) << endl;
	}
}

void exercise2(string & input) {

	printShrinkingMore(input);
}

void printShrinkingMore(string & input) {

	size_t half = input.length() / 2 + 1;
	for (size_t i {0}; i < half; i++) {

		int currSize = input.length() - i * 2;
		cout << string(i, ' ') << input.substr(i, currSize) << endl;
	}
}

