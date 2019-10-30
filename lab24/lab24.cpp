/**
 * lab25.cpp
 * CS 201
 * Bryan Beus
 * October 30, 2019
 * Using STL Algorithms
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
using std::sort;

int main(int argv, char **argc) {

	vector<string> dataset {"z", "b", "w", "d", "h", "f", "l", "p", "i", "o"};
	for (auto str: dataset)
		cout << str << " ";
	cout << endl;

	cout << "sort algorithm: " << endl;

	sort (dataset.begin(), dataset.end());
	for (auto str: dataset)
		cout << str << " ";
	cout << endl;

	cout << "reverse algorithm: " << endl;

	reverse (dataset.begin(), dataset.end());
	for (auto str: dataset)
		cout << str << " ";
	cout << endl;

	cout << "fill algorithm: " << endl;

	auto iter1 = dataset.begin() + 2;
	auto iter2 = dataset.end() - 2;
	fill (iter1, iter2, "x");
	for (auto str: dataset)
		cout << str << " ";
	cout << endl;

    return 0;
}

