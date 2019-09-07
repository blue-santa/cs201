/**
 * diamond.cpp
 * Bryan Beus
 * 7 Sept 2019
 * Diamond assignment for CS 201
 */

#include <iostream>
#include <string>

using namespace std;

int main() {

    int num_lines;
    cout << "Enter the number of lines to print in the diamond: ";

    cin >> num_lines;

    if (num_lines == 0 | num_lines < 0 | cin.fail()) {

        cout << "The value you entered is not a valid number" << endl;

        return 0;
    } 



    return 0;
}
