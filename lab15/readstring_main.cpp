/**
 * readstring_main.cpp
 * CS 201
 * Bryan Beus
 * October 7, 2019
 * The main file 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#include "readstring.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::istringstream;

int main(int argc, char **argv) {

    vector<string> text {"69", "69a", "a69", "5.6", "    68", "\t11", "68 69", "0xA"};

    printSquares(text);

    cout << "Part 2: " << endl;


    for (size_t i {0}; i < text.size(); i++) {
        istringstream instream(text.at(i));
        int num;
        instream >> num;
        if (!instream) {
            cout << "err" << endl;
        } else {
            printSquares2(num);
        }
    }

	return 0;
}

