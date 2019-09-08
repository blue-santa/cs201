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

    float km_per_m = 1.609;

    float input;

    cout << "Enter the number of miles to convert to kilometers: ";

    cin >> input;

    if (cin.fail()) {
        cout << "The value you entered is not a valid number. Please enter a numerical value." << endl;
        return 0;
    } 

    cout << "The number of kilometers in " << input << " miles is: " << input * km_per_m << endl;

    return 0; 
}
