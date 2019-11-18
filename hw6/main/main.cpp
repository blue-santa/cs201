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

int RandomBetweenU(int first, int last, std::mt19937 &e1);
int RandomBetweenN(int first, int last, std::mt19937 &e1);
int RandomBetween(int first, int last);
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

	// Print the normal histogram
	PrintDistribution(standardHistogram);

	return 0;
}

int RandomBetweenU(int first, int last, std::mt19937 &e1) {

	std::uniform_int_distribution<int> uniform_dist(first, last);
	int val = uniform_dist(e1);

	return val;

}

int RandomBetweenN(int first, int last, std::mt19937 &e1) {

	std::normal_distribution<> normal_dist(4, 1), min(first), max(last);
	int val = normal_dist(e1);

	return val;
	
}

int RandomBetween(int first, int last) {
	int val = (std::round(std::rand()));
	val = val % 6;
	val++;
	return val;

} 

void PrintDistribution(const std::map<int, int> &numbers) {

	for (auto p: numbers) {
		if ( p.first > 1 || p.first < 6) {
			cout << std::fixed << std::setprecision(1) << std::setw(2) << p.first << ' ' << std::string(p.second/20, '*') << endl;
		} else {
			cout << std::fixed << std::setprecision(1) << std::setw(2) << p.first << ' ' << "# of instances: " << p.second << endl;
		}
	}

	cout << endl;
}
 