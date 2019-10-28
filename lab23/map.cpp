/**
 * map.cpp
 * CS 201
 * Henryk Sosnowski and Bryan Beus
 * October 28, 2019
 * Create and manipulate a map
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <functional>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::istringstream;
using std::ostringstream;
using std::find; 
using std::ifstream;
using std::function;
using std::thread;
using std::time_t;
using std::setw;
using std::left;
using std::right;
using std::map;
using std::make_pair;
using std::to_string;

int main(int argv, char **argc) {

    map<int, string> myMap;

    for (int i = 0; i < 5; i++) {
        int randomNum = (rand() + 10000) % 1000;
        string myString = "String " + to_string(randomNum);
        cout << "Adding pair: " << randomNum << " " << myString << endl;
        myMap.insert(make_pair(randomNum, myString));
    }

    cout << endl;

    map<int, string>::iterator it = myMap.begin();

    while (it != myMap.end()) {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }


    return 0;
}

