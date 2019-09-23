/**
 * Lab 06
 * CS 201
 * Bryan Beus
 * September 16, 2019
 * Lab 6: Manipulating Strings
 */

#include <iostream>
#include <string>
#include <vector>

void exercise1(std::vector<std::string> & v);

void exercise2(std::vector<std::string> & v);

void exercise3(std::vector<std::string> & v);

int main(int argc, char **argv) {

	std::vector<std::string> v;

	std::cout << "Please provide three strings of varying lengths." << std::endl;
	
	for (int i = 0; i < 3; i++) {
		std::cout << "String " << i + 1 << ": ";

		while (true) {

			std::string input;
			std::cin >> input;

			if (std::cin.fail()) {
				std::cout << "The value you provided is invalid. Please try again." << std::endl;
			} else {
				v.push_back(input);
				break;
			}
		}
	}

	exercise1(v);
	exercise2(v);
	exercise3(v);

	return 0;
}

void exercise1(std::vector<std::string> & v) {

	std::cout << std::endl << "Printing strings: " << std::endl << std::endl;
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << std::endl;
	}
	
}

void exercise2(std::vector<std::string> & v) {

	std::cout << std::endl << "Printing pounds of string length: " << std::endl << std::endl;
	for (int i = 0; i < v.size(); i++) {
		std::cout << std::string(v.at(i).length(), '#') << std::endl;
	}
	
}

void exercise3(std::vector<std::string> & v) {

	std::cout << std::endl << "Printing strings backwards: " << std::endl << std::endl;
	for (int i = 0; i < v.size(); i++) {
		for (int j = v.at(i).length(); j >= 0; j--) {
			std::cout << v.at(i)[j];
		}
		std::cout << std::endl;
	}
	
}
