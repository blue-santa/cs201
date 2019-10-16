/**
 * @file     insertion_sort.cpp
 * @author   Student Name
 * @version  Feb 17, 2019
 * John Quan 
 * @brief    
 */

#include <algorithm>
#include <iostream>
#include <vector>
// for timer
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <sstream>

#include "insertion_sort.hpp"

using std::rand;

int main() {
	std::vector<int> original;

	for (int i {20000}; i > 0; i--) {
		original.push_back(i);
	}

	// your unsorted original
	// std::cout << "Original vector:" << std::endl;
	// printVector(original);
	// std::cout << std::endl << std::endl;

	// make a copy and sort the vector using the STL for comparison
	std::vector<int> sorted = original;
	std::sort(sorted.begin(), sorted.end());

	// start timer
	clock_t timer = clock();

	// call your sort function
	insertionSort(original);

	// stop timer
	timer = clock() - timer;

	// STL sorted vector
	// std::cout << "Sorted vector:" << std::endl;
	// printVector(sorted);
	// std::cout << std::endl << std::endl;

	// your sorted original
	// std::cout << "Your vector:" << std::endl;
	// printVector(original);
	// std::cout << std::endl << std::endl;

	// does it match STL sorted vector?
	if (isEqual(original, sorted)) {
		std::cout << "Your vector is sorted!!";
	} else {
		std::cout << "Your vector is NOT sorted.";
	}
	std::cout << std::endl << std::endl;

	printf("Sorted in approximately %f seconds",
			(float) timer / CLOCKS_PER_SEC);

	return 0;
}
