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

vector<int> collection;
int input;
bool cont = true;
int final_val;

void request_int() {
    cout << "Enter a positive integer (0 or negative to end): ";
}

int calculate_final() {

    int current = collection.at(0); 

    for (int i = 0; i < collection.size(); i++) {
        if (collection.at(i) > current) {
            current = collection.at(i);
        }
    }

    return current;
}

int main() {

    cout << "Provide a sequence of positive integers, ending with zero or a negative number." << endl;

    while (cont) {
        
        request_int();
        cin >> input; 

        if (input > 0 && !cin.fail()) {
            collection.push_back(input);
        } else if (cin.fail()) {
            cout << "The value you entered is not an integer." << endl;
            cout << "Please restart the program." << endl;
            cont = false;
            return 0;
        } else if (input <= 0 && collection.size() > 0) {
            cont = false;
            final_val = calculate_final();
        } else if (input <= 0 && collection.size() == 0) {
                cout << "Please enter an integer greater than 0 before ending the program." << endl;
        } else {
            cout << "We encountered an unexpected error. Please review the source code." << endl;
            cont = false;
            return 0;
        } 
    }

    cout << endl;
    cout << "The greatest number entered: " << final_val << endl; 

    return 0;
}

