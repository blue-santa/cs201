/**
 * lab24.cpp
 * CS 201
 * Bryan Beus
 * November 1, 2019
 * STL iterator assignment
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
using std::pair;
using std::to_string;
using std::sort;
using std::mismatch;

int main(int argv, char **argc) {

	vector<int> v1 {1, 2, 3, 4, 5, 6};
	vector<int> v2 {1, 2, 9, 10, 11, 12};


	pair<vector<int>::iterator, vector<int>::iterator> myMismatch;

	myMismatch = mismatch(v1.begin(), v1.end(), v2.begin());

	if (myMismatch.first != v1.end()) 
		cout << "Mismatching elements: " << *myMismatch.first << " and " << *myMismatch.second;
	else 
		cout << "Vectors match" << endl;

	return 0;
}

