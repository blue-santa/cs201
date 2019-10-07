/**
 * vector_manip.cpp
 * CS 201
 * Bryan Beus
 * September 30, 2019
 * The function definition file for vector_manip
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "vector_manip.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

void printList(vector<string> & list) {

	for (auto str: list)
		cout << str << " ";
	cout << endl;
}

void changeList(vector<string> & list, char & letter) {
	for (size_t i {0}; i < list.size(); i++) {

		if (!list.at(i).empty()) { 
			list.at(i)[0] = letter;
		}
	}
}

void requestSentinel(string & sentinel) {
	cout << "What word do you want to serve as the sentinel value? ";

	while (true) {
		cin >> sentinel;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please try again: ";
		} else {
			break;
		}
	}
}

void requestAdditional(vector<string> & initList, string sentinel) {
	cout << "Please input new words. When finished, use the sentinel value, " << sentinel << ", to stop.";

	string temp;

	while (true) {
		cout << "> ";

		getline(cin, temp);

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please try again: ";
		} else if (temp == sentinel) {
			break;
		} else {
			initList.push_back(temp);
		}
	}
}
