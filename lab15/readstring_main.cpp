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
#include <sstream>

// #include "vector_manip.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::istringstream;

void printSquares(vector<string> & text);
void printSquares2(int & num);

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

void printSquares(vector<string> & text) {

    for (size_t i {0}; i < text.size(); i++) {
        istringstream instream(text.at(i));
        int num;
        instream >> num;
        if (!instream) {
            cout << "err" << endl;
        } else {
            cout << num * num << endl;
        }
    }

}

void printSquares2(int & num) {
    cout << num * num << endl;
}
