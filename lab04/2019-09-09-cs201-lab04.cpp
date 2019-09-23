/**
 * Lab 04
 * Bryan Beus
 * September 11, 2019
 * Lab 04 assignment
 */

#include <iostream>
#include <string>
#include <vector>

void exercise1() { 

	for (int i = 1; i <= 100; i++) {
		switch (i % 3) 
		{
			case 0:
				std::cout << "Fizz" << std::endl;
			default :
				std::cout << i << std::endl;
		}
	}
}

void exercise2() { 

	for (int i = 1; i <= 100; i++) {

		if (i % 3 == 0 && i % 5 != 0) {
			std::cout << "Fizz" << std::endl;
		} else if (i % 3 != 0 && i % 5 == 0) {
			std::cout << "Buzz" << std::endl;
		} else if (i % 3 == 0 && i % 5 == 0) {
			std::cout << "Fizz Buzz" << std::endl;
		} else {
			std::cout << i << std::endl;
		}
	}
}

int main() {

	exercise1();
	exercise2();

	return 0;
}
