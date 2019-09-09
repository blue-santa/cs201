/**
 * greatest.cpp
 * Bryan Beus
 * 7 Sept 2019
 * Greatest assignment for CS 201
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Declare a vector to hold all user inputs

vector<int> collection;

// Declare a variable to hold each user input

int input;

// Declare a bool vector to indicate whether or not the user inputs allow for a while loop to end

bool cont = true;

// Declare the final variable that holds the greatest integer

int final_val;

// A function to request user input

void request_int() {
    cout << "Enter a positive integer (0 or negative to end): ";
}

// A function to calculate the final result

int calculate_final() {

    // Declare the current largest integer, and set it equal to the first user input in the vector

    int current = collection.at(0); 

    // Iterate through the user inputs
    // If any user input is larger than the current largest user input, set the new largest integer as the current largest

    for (int i = 0; i < collection.size(); i++) {
        if (collection.at(i) > current) {
            current = collection.at(i);
        }
    }

    // Return the final largest integer

    return current;
}

int main() {

    // Request user input

    cout << "Provide a sequence of positive integers, ending with zero or a negative number." << endl;

    // Initiate a while loop that continues until the user has finished inputting integers

    while (cont) {
        
        request_int();
        cin >> input; 

        // Test that the user input is valid

        if (cin.fail()) {
            cont = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl;
            cout << "The value you entered is not an integer. Please restart the program." << endl;
            return 0;

            // If the user input is less than or equal to zero, assume that the user is finished and calculate the final result


            // If the input is not valid, end the program

        } else if (input > 0 && !cin.fail()) {
            collection.push_back(input);
        } else if (input <= 0 && collection.size() > 0) {
            cont = false;
            final_val = calculate_final();
        } else if (input <= 0 && collection.size() == 0) {

            // If the user input is less than or equal to zero, but there are not integers in the vector, request the user to continue inputting integers

                cout << "Please enter an integer greater than 0 before ending the program." << endl;

                // Catchall error

        } else {
            cout << "We encountered an unexpected error. Please review the source code." << endl;
            cont = false;
            return 0;
        } 
    }

    // Add an extra line for formatting

    cout << endl;

    // Return the final result

    cout << "The greatest number entered: " << final_val << endl; 

    return 0;
}

