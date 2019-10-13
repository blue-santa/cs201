/**
 * userInputMain.cpp
 * CS 201
 * Bryan Beus
 * September 30, 2019
 * The main file for userInput project
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

int main(int argc, char **argv) {

	vector<string> userInput;
	vector<string> userInput2;
	vector<string> userInput3;

	exercise1(userInput);
	exercise2(userInput, userInput2);
	exercise3(userInput, userInput3);

	return 0;
}

