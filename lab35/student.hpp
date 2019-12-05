/*
 * student.hpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Header file for student_main.cpp lab 
 */

#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <map>

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

class Student
{
	private:

		string _name;
		int _id;

	public:

		Student(); 
		Student(string name); 
		Student(string name, int id);

		void printInfo() const;

};

#endif
