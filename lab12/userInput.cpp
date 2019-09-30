/**
 * userInput.cpp
 * CS 201
 * Bryan Beus
 * September 30, 2019
 * The function definition file for userInput
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "userInput.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

void exercise1(vector<string> &userInput) {

	requestUserInput(userInput);

	printUserInput(userInput);

}

void exercise2(vector<string> &userInput, vector<string> &userInput2) {

	filterInput1(userInput, userInput2);

	printUserInput(userInput2);

}


void exercise3(vector<string> &userInput, vector<string> &userInput3) {

	filterInput2(userInput, userInput3);

	printUserInput(userInput3);

}


void requestUserInput(vector<string> &userInput) {

	cout << "Please provide a list of words." << endl;
	cout << "The program will stop accepting words whenever it encounters the word \"end\"." << endl;

	string nextBatch;

	while (true) {

		cout << "\nNext batch: ";

		cin >> nextBatch;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input, please try again." << endl;
		} else if (nextBatch == "end") {
			break;
		} else {
			userInput.push_back(nextBatch);
		}
	}
}

void printUserInput(vector<string> &input) {

	for (auto str: input)
		cout << str << " ";

	cout << endl;
}

void filterInput1(vector<string> &userInput, vector<string> &userInput2) {
	vector<string> temp;
	for (auto str: userInput)
		if (str.length() == 5)
			temp.push_back(str);

	userInput2 = temp;
}

void filterInput2(vector<string> &userInput, vector<string> &userInput3) {
	vector<string> temp;
	for (auto str: userInput)
		if (str.find('x') != string::npos)
			temp.push_back(str);

	userInput3 = temp;
}


