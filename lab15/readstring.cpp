/**
 * readstring.cpp
 * CS 201
 * Bryan Beus
 * October 7, 2019
 * The function definition file
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "readstring.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline; 
using std::istringstream; 

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
