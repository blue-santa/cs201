/**
 * lab8.cpp
 * CS 201
 * September 20, 2019
 * Bryan Beus
 * Lab 8
 */

#include <iostream>
#include <string>
#include <vector>

#include "intio.hpp"
#include "lab8.hpp"

int doInput() {
	return getInt();
}

int compute(int input) {
	if (input <= 0) {
		return 0;
	}

	std::vector<int> divisibles;

	for (int i = 1; i < input; i++) {
		if (input % i == 0) {
			divisibles.push_back(i);
		}
	}
	int final_val = divisibles.size();
	
	return final_val;
}

