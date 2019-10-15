/**
 * databaseMain.cpp
 * CS 201
 * Bryan Beus
 * October 14, 2019
 * The main file for database project
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>

// #include "database.hpp"

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

bool createRecord() {

    return true;
}

bool readRecord() {

    return true;
}

bool updateRecord() {

    return true;
}

bool deleteRecord() {

    return true;
} 

int main(int argc, char **argv) {

    vector<vector <string> > taoTeChing (81);

    string filename = "tao_te_ching.txt";

    // Load Tao Te Ching into database
    ifstream in(filename);

    if (!in) {
        cerr << "Cannot open file: " << filename << endl;
        return 0;
    }

    string line;
    int chapterCount {-1};

    while (getline(in, line)) {
       istringstream instream(line);
       string firstWord;

       instream >> firstWord;
       if (firstWord == "Chapter") {
            chapterCount++;
       } else {
            taoTeChing[chapterCount].push_back(line);
            cout << line << endl;
       }
    }


    for (size_t i {0}; i < taoTeChing.size(); i++) {
        cout << "Chapter " << i << endl;
        cout << endl;
        for (size_t j {0}; j < taoTeChing.at(i).size(); j++) {
            cout << taoTeChing[i].at(j) << endl;
        }
        cout << endl;
        cout << endl;
    }

	return 0;
}

