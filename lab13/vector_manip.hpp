/**
 * vector_manip.hpp
 * CS 201
 * Bryan Beus
 * October 2, 2019
 * Header file for vector manip
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

#ifndef VECTORMANIP
#define VECTORMANIP
void printList(vector<string> & list);
void changeList(vector<string> & list, char & letter);
void requestSentinel(string & sentinel);
void requestAdditional(vector<string> & initList, string sentinel);
#endif
