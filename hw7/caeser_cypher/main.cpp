/*
 * main.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Main file for caesar cypher in hw7
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

#include "caesar_cypher.hpp"

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
using std::getline;

int main() {
	bool isFinished = false;
	clearConsole();

	while (!isFinished) {

		string user_input;
		int shift_amount;

		capture_user_input_string(user_input, isFinished);

		if (isFinished) {
			break;
		}

		capture_user_input_int(shift_amount); 

		string res_str;

		shift_message(user_input, shift_amount, res_str);

		cout << endl << "The new message is: " << res_str << endl << endl;

	} 

	// Print goodbye message
	cout << endl << "Program complete" << endl;

	return 0; 
}


