#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int RandomBetweenU(int first, int last, std::default_random_engine &e1);
int RandomBetweenN(int first, int last);
int RandomBetween(int first, int last);
void PrintDistribution(const std::map<int, int> &numbers);
 
int main()
{
    // Seed with a real random value, if available
    std::random_device r;

    int first = 1;
    int last = 6;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(first, last);

    int test_one = RandomBetweenU(first, last, e1);
    
    cout << "Test_one: " << test_one << endl;


    // Previous example code
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
 
    // Generate a normal distribution around that mean
    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()}; 
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);
 
    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(normal_dist(e2))];
    }
    std::cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

int RandomBetweenU(int first, int last, std::default_random_engine &e1) {

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
 
