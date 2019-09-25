/**
 * declarations.cpp
 * Bryan Beus
 * CS 201
 * September 24, 2019
 * The declarations file
 */

#include <iostream>
#include <string>
#include <vector>

#include "divisibles.hpp"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

bool isDiv3 (int & value) {

	bool result = false;

	if (value % 3 == 0) {
		result = true;
	}

	return result;
}

bool isADivB (int & a, int & b) {

	bool result = false;

	if (a % b == 0) {
		result = true;
	}

	return result;
}

void requestInput(int & a, int & b) {

	cout << "Please provide integer a: ";

	while (true) {
		cin >> a;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please try again: ";
		} else {
			break;
		}
	}

	cout << "Please provide integer b (should be less than a): ";

	while (true) {
		cin >> b;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please try again: ";
		} else if (b > a) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "b should be lesser in value than a: ";
		} else {
			break;
		}
	}
}

bool calculateRes(int & i, int & b) {
	bool result = false;

	if (i % b == 0) {
		result = true;
	}

	return result;
}

