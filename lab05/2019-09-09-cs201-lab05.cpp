/**
 * lab05.cpp
 * Bryan Beus
 * September 13, 2019
 * Create a switch and an if-else-if statement
 */

#include <iostream>
#include <string>

void print_options() {
	std::cout << "Provide an input from the list: " << std::endl;
	std::cout << "Input '1') Say hello world" << std::endl;
	std::cout << "Input '2') Count to 10" << std::endl;
	std::cout << "Input '3') Crash the program" << std::endl;
	std::cout << "Input '0') End the program" << std::endl;
}

bool perform_tasks(int input) {

	switch (input) {
		case 0: 
			return false;
			break;
		case 1:
			std::cout << "Hello, world" << std::endl;
			break;
		case 2:
			for (int i = 0; i < 10 ; i++) {
				std::cout << i + 1 << std::endl;
			};
			break;
		case 3: 
			std::cout << "Aughghghgh!" << std::endl;
			break;
		default: 
			std::cout << "Invalid input" << std::endl;
			break;
	}

	return true;
}

bool perform_tasks_2(int input) {

	if (input == 0) {
		return false;
	} else if (input == 1) {
		std::cout << "Hello, world" << std::endl;
	} else if (input == 2) {
		for (int i = 0; i < 10 ; i++) {
			std::cout << i + 1 << std::endl;
		};
	} else if (input == 3) { 
		std::cout << "Aughghghgh!" << std::endl;
	} else { 
		std::cout << "Invalid input" << std::endl;
	}

	return true;
}

void exercise1() {

	int input;

	bool cont_proc = true;

	while (cont_proc) {

		print_options();

		std::cin >> input;

		if (std::cin.fail() || (input < 0 || input >= 4)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "You provided an invalid input. Please try again." << std::endl;
		} else {
			cont_proc = perform_tasks(input);
		} 
	}
}

void exercise2() {

	int input;

	bool cont_proc = true;

	while (cont_proc) {

		print_options();

		std::cin >> input;

		if (std::cin.fail() || (input < 0 || input >= 4)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "You provided an invalid input. Please try again." << std::endl;
		} else {
			cont_proc = perform_tasks_2(input);
		} 
	}
}

int main() {

	exercise1();
	exercise2();

	return 0;
}
