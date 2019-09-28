/**
 * collatz.cpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * User inputs an integer, and the program prints the collatz sequence beginning at user's integer
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

void waitForContinue();

void clearConsole();

void clearCin();

void requestInput(int & userInput, bool & contLoop);

vector<int> calculateResult(int & userInput);

void printResult(vector<int> & result);

int main(int argc, char **argv) {

    // Declare program variables for user input, continuing the endless loop, and calculating the result

   int userInput;
   bool contLoop = true;
   vector<int> result;

   // Ensure the console is clear

   clearConsole();

   // Initiate endless while loop that continues so long as user does not indicate a desire to stop program

   while (contLoop) {

       // Request input from the user

       requestInput(userInput, contLoop);

       // If the user's response did not indicate a desire to stop the program, calculate the Collatz Sequence and print it

       if (contLoop) {
            result = calculateResult(userInput);
            printResult(result); 
       } else {

           // If the user's response did indicate a desire to stop the program, end the while loop

            break;
       } 
   }

    return 0;

}

// Wait for the user to indicate that they are ready to continue

void waitForContinue() {

    cout << endl << "Press enter to continue...";
    getchar();
}

// Clear the console

void clearConsole() {

        // Clear the console

    cout << "\033[2J\033[1;1H";

}

// Ensure the cin buffer is clear

void clearCin() {
    cin.clear();
    cin.ignore(1000, '\n'); 
} 

// Request input from the user

void requestInput(int & userInput, bool & contLoop){

    // Ensure the console screen is clear

    clearConsole();

    // Prompt the user

    cout << "Please provide the starting integer for the Collatz Sequence. (To end the program, enter a non-integer value, such as a character.)" << endl;

    // Initiate endless while loop that continues until valid input is received 

    while (true) {

        // Receive user input

        cin >> userInput;

        // If user input is invalid, this means the user desires to stop the program

        if (cin.fail()) {
            contLoop = false;
            clearCin();
            break;
            
        // If the user input is less than 1, repeat the request for input

        } else if (userInput < 1) {
            clearCin();
            cout << "The sequence requires that the starting integer be greater than or equal to one. Please try again: ";

        // Otherwise, the input is valid and the request-loop is stopped

        } else {
            break;
        }
    }
}

// Calculate the Collatz Sequence

vector<int> calculateResult(int & userInput) {

    // Initiate variable to track progression of Collatz Sequence calculations
    // Initiate at user's starting value

    int currValue = userInput;

    // Declare result vector, to be returned at conclusion of calculations

    vector<int> result;

    // Initiate while loop to continue iterating through Collatz functions until currValue is valued at 1

    while (currValue > 1) {

        // Place current value into the result vector 

        result.push_back(currValue);

        // If the variable is even, perform the second Collatz function

        if (currValue % 2 == 0) {
            currValue = currValue / 2;

        // Otherwise, perform the first Collatz function

        } else {
            currValue = currValue * 3 + 1;
        } 
    }

    // Place the final "1" value into the result vector

    result.push_back(1);

    // Return the result

    return result; 

}

// Print the result

void printResult(vector<int> & result) {

    // Ensure the console is clear

    clearConsole();

    // Indicate upcoming actions

    cout << "Collatz Sequence starting with integer: " << result.at(0) << endl << endl;

    // Print the Collatz Sequence for the user's input

    for (size_t i {0}; i < result.size(); i++) {
        cout << result.at(i) << " ";
    }

    // Provide formatting

    cout << endl << endl;

    // Ensure all cin inputs are clear

    clearCin();

    // Wait for user to finish reading

    waitForContinue();

}

