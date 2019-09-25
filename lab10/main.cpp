/**
 * main.cpp
 * CS 201
 * Bryan Beus
 * September 24, 2019
 * The main file
 */

#include <iostream>
#include <string>
#include <vector>

#include "divisibles.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(int argc, char **argv) {

	int a;
	int b;
	vector<int> collection;

	for (int i = 1; i < 41; i++) {
		if (isDiv3(i) == true) {
			cout << i << endl;
		}

	}

	requestInput(a, b);

	for (int i = 1; i <= a; i++) {
		if (calculateRes(i, b) == true) {
			cout << i << endl;	
		}
	}

	return 0;

	
}
