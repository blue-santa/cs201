/**
 * grid.cpp
 * Bryan Beus
 * 8 Sept 2019
 * Grid assignment for CS 201
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void print_top_line() {

    for (int j = 0; j < 5; j++) {
        cout << " ";
    }

    for (int i = 1; i <= 8; i++) {

        cout << i;

        for (int j = 0; j < 5; j++) {
            cout << " ";
        }

    }

    cout << endl;

    cout << "  ╔";

    for (int i = 0; i < 7; i++) {

        for (int i = 0; i < 5; i++) {
            cout << "═";
        }

        cout << "╦";

    }

    for (int i = 0; i < 5; i++) {
        cout << "═";
    }

    cout << "╗" << endl;
}

void print_bottom_line() {

    cout << "  ╚";

    for (int i = 0; i < 7; i++) {

        for (int i = 0; i < 5; i++) {
            cout << "═";
        }

        cout << "╩";

    }

    for (int i = 0; i < 5; i++) {
        cout << "═";
    }

    cout << "╝" << endl;
}

int main() {

    vector<string> collection(64, ".");

    // box.push_back("╔");
    // box.push_back("═");
    // box.push_back("╦");
    // box.push_back("╗");

    // cout << collection.at(1) << endl;

    print_top_line();

    print_bottom_line();

    return 0;
}
