/**
 * source.cpp
 * CS 201
 * Bryan Beus
 * September 18, 2019
 * Combination of intio.hpp and intio.cpp for Lab 07
 */

#include <string>
#include <iostream>
#include <vector>

#include "intio.hpp"

using std::cout;
using std::endl;

void exercise1() {


	std::vector<int> integers;

	for (int i = 0; i < 3; i++) {
		int num = getInt(); 
		integers.push_back(num);
	}

	cout << endl;

	for (int i = 0; i < integers.size(); i++) { 
		putInt(integers.at(i), 15);
		cout << endl;
	}
	
}

void exercise2() {

	std::vector<int> integers;

	cout << "\nPlease input at least one number. End by inputting 0." << endl;


	while (true) {
		int num = getInt();

		if (num == 0 &&  integers.size() != 0) { 
			break; 
		}

		integers.push_back(num);
	}

	cout << endl;

	int sum = 0;

	for (int i = 0; i < integers.size(); i++) { 
		sum = sum + integers.at(i); 
	}
	
	cout << "Final sum: " << sum << endl;
	
}

void exercise3() {

	std::vector<int> integers;

	cout << endl;

	while (true) {
		int num = getInt();
		if (num == 0 &&  integers.size() != 0) { 
			break; 
		}
		integers.push_back(num);
	}

	cout << endl;

	int sum = integers.at(0);
	for (int i = 0; i < integers.size(); i++) { 
		if (sum > integers.at(i)) {
			sum = integers.at(i);
		}
	}
	
	cout << "Lowest value int: " << sum << endl;

}
int main(int argc, const char **argv) {

	exercise1();
	exercise2();
	exercise3();
	return 0;
}
