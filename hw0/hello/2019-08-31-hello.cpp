/**
 * hello.cpp
 * Bryan Beus
 * 4 Sept 2019
 * Hello, World example for CS 201
 */

#include <iostream>
#include <string>
using namespace std;

int main() {

    // Declare a string variable for "Hello world"
    string hello = "Hello, World";

    // Initiate a counting sequence for iteration
    int count = 0;

    while (count != 5) {
        
        // Print string to console
        cout << hello << endl;

        // Increase count each time
        count += 1;
    }

    return 0;
}
