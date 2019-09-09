/**
 * mileskm.cpp
 * Bryan Beus
 * 7 Sept 2019
 * Mileskm assignment for CS 201
 */

#include <iostream>
#include <string>

using namespace std;

int main() {

    // Set a default conversion value for kilometers

    float km_per_m = 1.609;

    // Declare a variable for user input

    float input;

    // Request user input

    cout << "Enter the number of miles to convert to kilometers: ";

    cin >> input;

    // Test that the user input is valid, and if not, end the program

    if (cin.fail()) {
        cout << "The value you entered is not a valid number. Please enter a numerical value." << endl;
        return 0;
    } 

    // Return the final result and calculations

    cout << "The number of kilometers in " << input << " miles is: " << input * km_per_m << endl;

    return 0; 
}
