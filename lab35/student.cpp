/*
 * student.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Function definition file for student_main.cpp
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <map>

#include "student.hpp"

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::make_pair;
using std::for_each;
using std::getline;
using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::find;
using std::map;
using std::setw;
using std::left;

Student::Student() {

	_name = "Unknown";
	_id = -1;

}

Student::Student(string name) {

	_name = name;

	_id = -1;

}

Student::Student(string name, int id) {

	_name = name;
	_id = id;

}

void Student::printInfo() const { 
	cout << setw(8) <<  "Name:" << this->_name << endl;
	cout << setw(8) << "Id:" << this->_id << endl;

}
