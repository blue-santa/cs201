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
using std::stringstream;
using std::ifstream;
using std::rand;

void waitForContinue();

void calculateRes(string &pattern, string &userInput, int &bulls, int &cows);

int main(int argc, char **argv) {

    vector<int> ran_nums;
    srand (time(NULL));
    
    for (int i {0}; i < 4; i++) {
        int temp = rand() % 10;
        ran_nums.push_back(temp);
    }

    string pattern = "";
    
    for (size_t i {0}; i < ran_nums.size(); i++) {
        stringstream ss;
        ss << ran_nums.at(i); 
        pattern = pattern + ss.str();
    }
    cout << "Test: " << pattern << endl;

    cout << "Enter four characters to guess the correct pattern. (Hint: All correct answers are digits.)" << endl;

    int bulls;
    int cows;

    while (true) {
        string userInput;
        getline(cin, userInput);

        calculateRes(pattern, userInput, bulls, cows);

        cout << bulls << " bulls and " << cows << "cows" << endl;

        if (bulls == 4) {
            cout << "Congrats, you win!" << endl;
            waitForContinue();
            break;
        }
    }

	return 0;
}

void waitForContinue() {

    cout << endl << "Press enter to continue...";
    getchar();
}

void calculateRes(string &pattern, string &userInput, int &bulls, int &cows) {

    for (size_t i {0}; i < 4; i++) {
        unsigned int temp;
        temp = pattern.find(userInput[i]);

        if (userInput[i] == pattern[i]) {
            bulls++;
        } else if (temp != string::npos) {
            cows++;
        }
    }
}
