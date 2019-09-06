/**
 * CS201 Lab01
 * Bryan Beus
 * 4 Sept 2019
 * Lab 01 for CS 201
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int num;

    cout << "Please provide an integer: ";
    cin >> num;

    int base = num + 1;

    cout << "The result is: " << base * base << endl;

    return 0;
}
