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

   int userInput;
   bool contLoop = true;
   vector<int> result;

   clearConsole();

   while (contLoop) {

       requestInput(userInput, contLoop);

       if (contLoop) {
            result = calculateResult(userInput);
            printResult(result);
       } else {
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

void requestInput(int & userInput, bool & contLoop){

    clearConsole();

    cout << "Please provide the starting integer for the Collatz Sequence. (To end the program, enter a non-integer value, such as a character.)" << endl;

    while (true) {

        cin >> userInput;

        if (cin.fail()) {
            contLoop = false;
            clearCin();
            break;
        } else if (userInput < 1) {
            clearCin();
            cout << "The sequence requires that the starting integer be greater than or equal to one. Please try again: ";
        } else {
            break;
        }
    }
}

vector<int> calculateResult(int & userInput) {

    int currValue = userInput;

    vector<int> result;

    while (currValue > 1) {

        result.push_back(currValue);

        if (currValue % 2 == 0) {
            currValue = currValue / 2;
        } else {
            currValue = currValue * 3 + 1;
        } 
    }

    result.push_back(1);

    return result; 

}

void printResult(vector<int> & result) {

    clearConsole();

    cout << "Collatz Sequence starting with integer: " << result.at(0) << endl << endl;

    for (size_t i {0}; i < result.size(); i++) {
        cout << result.at(i) << " ";
    }

    cout << endl << endl;

    clearCin();

    waitForContinue();

}

