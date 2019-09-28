/**
 * lab11.cpp
 * CS 201
 * Bryan Beus
 * September 27, 2019
 * Write a program that repeatedly inputs a word ...
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

void requestInput(string & userInput);

vector<char> filterWord1(string & userInput);
vector<char> filterWord2(string & userInput);
vector<char> filterWord3(string & userInput);

void displayWord(vector<char> result);

int main() {
	
	string userInput;

	requestInput(userInput);

	vector<char> result1;
	vector<char> result2;
	vector<char> result3;

	result1 = filterWord1(userInput);
	result2 = filterWord2(userInput);
	result3 = filterWord3(userInput);

	displayWord(result1);
	displayWord(result2);
	displayWord(result3);

	cout << endl;

	return 0;
}

void requestInput(string & userInput) {
	
	cout << "\nPlease provide a new word: ";

	while (true) {
		cin >> userInput;

		if (cin.fail()) { 
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid input, please try again: ";
		} else {
			break;
		}
	}
}

vector<char> filterWord1(string & userInput) {
	vector<char> result;

	for (size_t i{0}; i < userInput.size(); i++) {
		if (islower(userInput[i])) {
			result.push_back(userInput[i]);
		}

	} 

	return result;

}

vector<char> filterWord2(string & userInput) {
	vector<char> result;

	for (size_t i{0}; i < userInput.size(); i++) {
		if (isupper(userInput[i])) {
			result.push_back(userInput[i]);
		}

	} 

	return result;

}

vector<char> filterWord3(string & userInput) {
	vector<char> result;

	for (size_t i{0}; i < userInput.size(); i++) {
		if (isupper(userInput[i]) || islower(userInput[i])) {
		} else { 
			result.push_back(userInput[i]);
		}

	} 

	return result;

}

void displayWord(vector<char> result) {

	for (size_t i {0}; i < result.size(); i++) {
		cout << result[i];
	}
	cout << endl;
}
