/**
 * vector_manip_main.cpp
 * CS 201
 * Bryan Beus
 * October 2, 2019
 * The main file for the vector_manip project
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

int main(int argc, char **argv) {

	vector<string> initList {"I", "am", "the", "eggman.", "I", "am", "the", "eggman.", "I", "am", "the", "walrus!"};

	printList(initList);

	char letter = 'x';

	changeList(initList, letter);

	printList(initList);

	string sentinel;

	requestSentinel(sentinel);

	requestAdditional(initList, sentinel);
	
	printList(initList);

	return 0;
}
