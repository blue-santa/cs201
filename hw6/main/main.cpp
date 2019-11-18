/*
 * main.cpp
 * CS 201
 * November 15, 2019
 * Bryan Beus
 * Main file for the histogram project in hw6
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

// Return a random number according to a uniform distribution
int RandomBetweenU(int first, int last, std::mt19937 &e1);

// Return a random number according to a normal distribution 
int RandomBetweenN(int first, int last, std::mt19937 &e1);

// Return a random number using the standard library rand() function
int RandomBetween(int first, int last);

// Print the provided distribution to the console
void PrintDistribution(const std::map<int, int> &numbers);
 
int main()
{
	// Declare endpoints of the range for the distributions 
	int first = 1;
	int last = 6;

	// Declare pseudo-random device for creating seeds
	std::random_device r;

	// Create a seed sequence to feed to the generator
	std::seed_seq seedObj{r(), r(), r(), r(), r(), r(), r(), r()}; 

	// Declare random-number generator and provide with seedObj sequence
	std::mt19937 e1(seedObj);

	// Create uniform historgram
	std::map<int, int> uniformHistogram;
	for (int i = 0; i < 10000; i++) {
		++uniformHistogram[std::round(RandomBetweenU(first, last, e1))];
	}

	// Print the uniform histogram
	PrintDistribution(uniformHistogram);

	// Create normal histogram
	std::map<int, int> normalHistogram;
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
	std::map<int, int> standardHistogram;
	for (int i = 0; i < 10000; i++) { 
		++standardHistogram[std::round(RandomBetween(first, last))];
	}

	// Print the standard histogram
	PrintDistribution(standardHistogram);

	return 0;
}

// Return a random value according to a uniform distribution
int RandomBetweenU(int first, int last, std::mt19937 &e1) {

	std::uniform_int_distribution<int> uniform_dist(first, last);
	int val = uniform_dist(e1);

	return val;

}

// Return a random value according to a normal distribution
int RandomBetweenN(int first, int last, std::mt19937 &e1) {

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
void PrintDistribution(const std::map<int, int> &numbers) {

	for (auto p: numbers) {
		cout << std::fixed << std::setprecision(1) << std::setw(2) << p.first << ' ' << std::string(p.second/200, '*') << endl;
	}

	cout << endl;
}
 
