/**
 * userInputMain.cpp
 * CS 201
 * Bryan Beus
 * September 30, 2019
 * The main file for userInput project
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>
#include <stdlib.h>

// #include "bulls-and-cows.hpp"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::find;
using std::istringstream;
using std::ifstream;
using std::rand;

int main(int argc, char **argv) {

    vector<int> pattern;
    srand (time(NULL));
    
    for (int i {0}; i < 4; i++) {
        int temp = rand() % 10;
        pattern.push_back(temp);
    }


	return 0;
}

