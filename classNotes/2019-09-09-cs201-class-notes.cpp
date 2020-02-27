/**
 * Bryan Beus
 * CS 201 Lab 3
 * 2019-09-09
 * Exercises with while loops
 */

#include <iostream>
#include <string>

using namespace std;

void exercise1() {
	int i = 1;
	while (i <= 20) {
		cout << i << " ";	
		i++;
	}	

	cout << endl;
}

void exercise2() {
	int i = 0;

	while (i < 10) {
		int j = 0;
		while (j < 60) {
			cout << "*";
			j++;
		}
		i++;
		cout << endl;
	} 
}

void exercise3() {
	int state = 0;
	int i = 0;

	while (i < 10) {
		int j = 0;
		while (j < 60) {
			if (state == 0) {
				cout << "*";
				state = 1;
			} else if (state == 1) {
				cout << "#";
				state = 0;
			}
			j++;
		}
		if (state == 1) {
			state = 0;
		} else if (state == 0) {
			state = 1;
		}
		i++;
		cout << endl;
	} 
}

int main(int argc, char** argv) {
	exercise1();
	exercise2();
	exercise3();
	return 0;
}
