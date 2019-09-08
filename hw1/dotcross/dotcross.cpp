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

    vector<float> dotcross;
    float input_A;
    float input_B;

    vector<string> xyz;
    xyz.push_back("Ax");
    xyz.push_back("Ay");
    xyz.push_back("Az");
    xyz.push_back("Bx");
    xyz.push_back("By");
    xyz.push_back("Bz");

    cout << "Provide three floating point numbers for vector A and three more for vector B: " << endl;

    while (dotcross.size() < 6) {
        cout << xyz.at(dotcross.size()) << ": ";
        cin >> input_A;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "The input you provided is not valid. Please try again." << endl;
        } else {
            dotcross.push_back(input_A);
        }
    }

    float dotprod = dotcross.at(0) * dotcross.at(3) + dotcross.at(1) * dotcross.at(4) + dotcross.at(2) * dotcross.at(5);
    vector<float> crossprod;
    crossprod.push_back(dotcross.at(1) * dotcross.at(5) - dotcross.at(2) * dotcross.at(4));
    crossprod.push_back(dotcross.at(2) * dotcross.at(3) - dotcross.at(0) * dotcross.at(5));
    crossprod.push_back(dotcross.at(0) * dotcross.at(4) - dotcross.at(1) * dotcross.at(3));

    cout << fixed << setprecision(5) <<  "A dot B = " << dotprod << endl;
    cout << "A cross B = (" << crossprod.at(0) << ", " << crossprod.at(1) << ", " << crossprod.at(2) << ")" << endl;

    return 0;
}
