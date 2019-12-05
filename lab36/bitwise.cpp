/*
 * bitwise.cpp
 * CS 201
 * December 02, 2019
 * Bryan Beus
 * Main file for lab36
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

void i_like(int drinks, const vector<int> &myDrinks) {

	cout << "Drinks I like: " << endl;

	if (drinks & myDrinks[0]) {
		cout << "Rootbeer" << endl;
		cout << sizeof(myDrinks[0]) << endl;
	}
	if (drinks & myDrinks[1]) {
		cout << "V8 Juice" << endl;
		cout << sizeof(myDrinks[1]) << endl;
	}
	if (drinks & myDrinks[2]) {
		cout << "Egg Nog" << endl;
		cout << sizeof(myDrinks[2]) << endl;
	}

}

int main() { 

	const int ROOTBEER = 1;
	const int V8JUICE = 2;
	const int EGGNOG = 4; 

	vector<int> myVec {ROOTBEER, V8JUICE, EGGNOG};

	i_like(ROOTBEER, myVec);
	i_like(V8JUICE | EGGNOG, myVec); 

	return 0;

}

