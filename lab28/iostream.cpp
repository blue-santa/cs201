/*
 * iostream.cpp
 * CS 201
 * Bryan Beus
 * November 8, 2019
 * Stream to a file
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::ofstream;

int main() {

	ofstream fout("file");
	if (!fout) {
		cout << "Error opening file" << endl;
		return 0;
	}

	for (int i = 1; i <= 100; i++) {
		fout << std::setw(3) << std::right;
		if (i != 100)
			fout << i;
		else 
			fout << std::setw(1) << " " << std::setw(3) << i;
		if (i % 10 == 0)
			fout << endl;
	}

	return 0;
}
