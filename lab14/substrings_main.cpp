/**
 * substrings.cpp
 * CS 201
 * Bryan Beus
 * October 4, 2019
 * The main file for the substrings project
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


int main(int argc, char **argv) {


	string input;

	requestInput(input);

	exercise1(input);

	exercise2(input);

	return 0;
}

