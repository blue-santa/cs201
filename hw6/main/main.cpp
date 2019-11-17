#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int RandomBetweenU(int first, int last, std::mt19937 &e1);
int RandomBetweenN(int first, int last);
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

	for (auto p: uniformHistogram) {
		cout << std::fixed << std::setprecision(1) << std::setw(2) << p.first << ' ' << std::string(p.second/200, '*') << endl;
	}

	int test_one = RandomBetweenU(first, last, e1); 
	cout << "Test_one: " << test_one << endl;


	// Previous example code
	std::uniform_int_distribution<int> uniform_dist(first, last);
	int mean = uniform_dist(e1);
	std::cout << "Randomly-chosen mean: " << mean << '\n';

	// Generate a normal distribution around that mean
	std::normal_distribution<> normal_dist(mean, 2);

	std::map<int, int> hist;
	for (int n = 0; n < 10000; ++n) {
		++hist[std::round(normal_dist(e1))];
	}
	std::cout << "Normal distribution around " << mean << ":\n";
	for (auto p : hist) {
		std::cout << std::fixed << std::setprecision(1) << std::setw(2)
			  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
	}
}

int RandomBetweenU(int first, int last, std::mt19937 &e1) {

	std::uniform_int_distribution<int> uniform_dist(first, last);
	int val = uniform_dist(e1);

	return val;

}

int RandomBetweenN(int first, int last) {

	int val = 0;
	return val;
	
}

int RandomBetween(int first, int last) {
	int val = 0;
	return val;

} 

void PrintDistribution(const std::map<int, int> &numbers) {

}
 
