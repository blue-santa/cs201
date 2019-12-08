/*
 * Environment.hpp
 * CS 201
 * December 7, 2019
 * Bryan Beus
 * Declaration file for Environment class
 */

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h> 
#include <utility>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::map;
using std::pair;
using std::make_pair;
using std::left;
using std::mt19937;

class Environment {

    private:

        // Member Variables 
        vector<bool> _rooms;
        mt19937 *_e1;

    public:

        // Constructors
        Environment(mt19937& e1);

        // Member Functions
        void cleanRoom();
        void iteration();
        int getTemp();
        bool getHeater();

};

#endif

int main()
{

	// Create normal histogram
	map<int, int> normalHistogram;
	for (int i = 0; i < 10000; i++) {
		int val;
		// Technically, a randomized normal distribution should never have defined endpoints
		// However, because the assignment lists 1 and 6 as the required range,
		// Only accept values that fit within the range
		while (true) {
			val = std::round(RandomBetweenN(first, last, e1));
			if (val <= last && val >= first)
				break;
		}
		++normalHistogram[val];
	}

	// Print the normal histogram
	PrintDistribution(normalHistogram);

	// Create standard rand() histogram
	map<int, int> standardHistogram;
	for (int i = 0; i < 10000; i++) {
		++standardHistogram[std::round(RandomBetween(first, last))];
	}

	// Print the standard histogram
	PrintDistribution(standardHistogram);

	return 0;
}

// Return a random value according to a uniform distribution
int RandomBetweenU(int first, int last, mt19937 &e1) {

	std::uniform_int_distribution<int> uniform_dist(first, last);
	int val = uniform_dist(e1);

	return val;

}

// Return a random value according to a normal distribution
int RandomBetweenN(int first, int last, mt19937 &e1) {

	std::normal_distribution<> normal_dist(4, 1), min(first), max(last);
	int val = normal_dist(e1);

	return val;

}

// Return a random value according to the default standard library
int RandomBetween(int first, int last) {
	// Acquire a random int value
	int val = (std::round(std::rand()));

	// Ensure the value is within six digits
	val = val % 6;

	// Add 1 to the value, to account for the 0 - 5 default range
	val++;

	// Return value
	return val;

}

// Print the provided distribution to the console
void PrintDistribution(const map<int, int> &numbers) {

	for (auto p: numbers) {
		cout << std::fixed << std::setprecision(1) << std::setw(2) << p.first << ' ' << std::string(p.second/200, '*') << endl;
	}

	cout << endl;
}


