/**
 * dotcross.cpp
 * Bryan Beus
 * 8 Sept 2019
 * Dotcross assignment for CS 201
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    // Declare a vector to hold user inputs

    vector<float> dotcross;

    // Declare a float variable to hold user inputs

    float input;

    // Declare a vector to hold the variables names

    vector<string> xyz;
    xyz.push_back("Ax");
    xyz.push_back("Ay");
    xyz.push_back("Az");
    xyz.push_back("Bx");
    xyz.push_back("By");
    xyz.push_back("Bz");

    // Request user input

    cout << "Provide three floating point numbers for vector A and three more for vector B: " << endl;

    // Initiate a while loop that continues until the user has provided all six inputs for vectors A and B

    while (dotcross.size() < 6) {

        // Request user input for the current vector variable

        cout << xyz.at(dotcross.size()) << ": ";
        cin >> input;

        // Test whether user input is valid, and if not, repeat the while loop
        // Otherwise, add the user input to the vector variables

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "The input you provided is not valid. Please try again." << endl;
        } else {
            dotcross.push_back(input);
        }
    }

    // Declare a dot product variable and perform the dot-product calculation

    float dotprod = dotcross.at(0) * dotcross.at(3) + dotcross.at(1) * dotcross.at(4) + dotcross.at(2) * dotcross.at(5);

    // Delcare a vector of the cross-product vector and perform each calculation
    vector<float> crossprod;
    crossprod.push_back(dotcross.at(1) * dotcross.at(5) - dotcross.at(2) * dotcross.at(4));
    crossprod.push_back(dotcross.at(2) * dotcross.at(3) - dotcross.at(0) * dotcross.at(5));
    crossprod.push_back(dotcross.at(0) * dotcross.at(4) - dotcross.at(1) * dotcross.at(3));

    // Report the results

    cout << fixed << setprecision(5) <<  "A dot B = " << dotprod << endl;
    cout << "A cross B = (" << crossprod.at(0) << ", " << crossprod.at(1) << ", " << crossprod.at(2) << ")" << endl;

    return 0;
}
