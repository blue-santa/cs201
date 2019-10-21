/**
 * stream_manip_manip.cpp
 * Bryan Beus
 * October 21, 2019
 * Dr. Metzgar 
 * Main file for lab 20    
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <ios>
#include <cmath>

// #include "insertion_sort.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;
using std::right;
using std::cos;
using std::setprecision;
using std::fixed;


int main(int argc, char **argv) {

	int currDeg = 0; 
	double currVal;

	while (currDeg <= 180) {

		currVal = cos(currDeg * M_PI/180);

		cout << setprecision(0);
		cout << setw(3);
		cout << right;
		cout << currDeg;

		cout << setprecision(8);
		cout << setw(12);
		cout << fixed;
		cout << currVal << endl;

		currDeg += 5;
	}

	return 0;
}

