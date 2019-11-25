/*
 * caesar_cypher.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Function definition file for caesar_cypher project in hw6
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

// Clear the console
void clearConsole() {

	cout << "\033[2J\033[1;1H";
}

