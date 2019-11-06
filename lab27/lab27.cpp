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

	int heads = 0;
	int tails = 0;

	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(1, 2);
	
	for (int i = 0; i < 1000; i++) {
		int temp = distribution(generator);
		if (temp == 1)
			heads++;
		else
			tails++; 
	}

	cout << "Heads: " << heads << endl;
	cout << "Tails: " << tails << endl;

	return 0;
}
