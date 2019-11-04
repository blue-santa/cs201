/**
 * @file     lambdas.hpp
 * @author   Student Name
 * @date     Mar 21, 2019
 * John Quan
 *
 * Practice using lambda functions
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>

#include "lambdas.hpp"

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;

using SizeStringPair = std::pair<size_t, std::string>;

int main() {

	// TODO: REQUIRED
	//       Create a vector<pair<size_t, string>> to enumerate
	//       each string in the WIKIPEDIA_CPP string vector.

	cout << "Part 1: " << endl;

	vector<SizeStringPair> v; 

	for (size_t i = 0; i < WIKIPEDIA_CPP.size(); i++) {
		size_t temp = WIKIPEDIA_CPP[i].length();
		v.push_back(make_pair(temp, WIKIPEDIA_CPP[i]));
	}

	// TODO: REQUIRED
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the first member in descending order.

	std::sort(v.begin(), v.end(), [](SizeStringPair a, SizeStringPair b) {
		return a.first < b.first;
	});

	// TODO: REQUIRED
	//       Use printVectorPairs() to print the vector

	cout << printVectorPairs(v.begin(), v.end()); 

	cout << endl << "Part 2: " << endl;
	
	// TODO: ADDITIONAL 1
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the second member in ascending order.

	std::sort(v.begin(), v.end(), [](SizeStringPair a, SizeStringPair b) {
		return a.first > b.first;
	}); 

	// TODO: ADDITIONAL 1
	//       Use printVectorPairs() to print the vector

	cout << printVectorPairs(v.begin(), v.end()); 

	// TODO: ADDITIONAL 2
	//       Use std::find_if with a comparison lambda function that prints
	//       the vector pairs where the pair's second.length() > 15.
	//       Print the vector as described in the lab.

	cout << endl << "Part 3: " << endl;

	vector<SizeStringPair>::iterator it = std::find_if(v.begin(), v.end(), [](SizeStringPair a) {
		return a.first > 15;
	});

	while (it->first > 15) { 
		std::cout << "{ "<< it->first << ", "<< it->second << " }" << std::endl; 
		it++;
	}

	return 0;
}
