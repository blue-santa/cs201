/*
 * lab27.cpp
 * CS 201
 * Bryan Beus
 * November 6, 2019
 * Generate random numbers
 */


#include <cstdlib>
#include <random>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;

int main() {

	cout << "Begin coin flip experiment." << endl;

	vector<size_t> shuffledDeck;

	for (size_t i = 1; i <= 100; i++) {
		cout << i << " ";
		shuffledDeck.push_back(i);
	}
	cout << endl << endl;;

	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(0, 99);
	
	for (size_t i = 0; i < shuffledDeck.size(); i++) {
		// Capture initial number
		int k = static_cast<int>(i);
		size_t part1 = shuffledDeck[k];

		// Generate a random index number within the range
		int num = distribution(generator);

		size_t part2 = shuffledDeck[num];

		shuffledDeck[k] = part2;
		shuffledDeck[num] = part1; 
	}

	for (size_t i = 0; i < shuffledDeck.size(); i++) {
		int k = static_cast<int>(i);
		cout << shuffledDeck[k] << " ";
	}
	cout << endl;

	return 0;
}
