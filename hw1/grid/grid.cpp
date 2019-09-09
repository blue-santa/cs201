/**
 * grid.cpp
 * Bryan Beus
 * 8 Sept 2019
 * Grid assignment for CS 201
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the number of Rows (R) and Columns (C)

#define R 5
#define C 5

// Define the Width of the blank spaces in the cells
// This must be an odd number

#define Width 5

// Set a default function to print a series of blank spaces of length <Width>

void print_full_width() {
    for (int j = 0; j < Width; j++) {
        cout << " ";
    } 
}

// Set a default function to print a series of blank spaces of half of length <Width>

void print_half_width() { 
    for (int j = 0; j < (Width - 1) / 2; j++) {
        cout << " ";
    } 
}

// Set a default function to print a series of double bars of length <Width>

void print_full_bar() {
    for (int i = 0; i < Width; i++) {
        cout << "═";
    } 
}

// Print the top of the grid

void print_top_line() {

    // Vertically clear at least one line in the terminal, then print the <Width> blank spaces

    cout << endl;

    print_full_width();

    // Print each column number, followed by <Width> blank spaces 

    for (int i = 1; i <= C; i++) {

        cout << i;

        print_full_width();
    }

    cout << endl;

    // Print the top row of the grid

    cout << "  ╔";

    for (int i = 0; i < C - 1; i++) {

        print_full_bar();

        cout << "╦";

    }

    print_full_bar();

    cout << "╗" << endl;
}

// A function to fill a whole row that has no variables or grid corners

void print_fill_row() {

    cout << "  ║";

    for (int i = 0; i < C; i++) {

        print_full_width();

        cout << "║";
    }

    cout << endl;
}

// A function to fill a row that has variables, including row numbers and variables inside the grid boxes
// Row requires both the current row to print and a vector that has the current state of grid boxes (X's or .'s)

void print_var_row(int row, vector< vector<string> > collection) {

    // Begin the row 

    cout << " " << row << "║";

    // Iterate through each grid box, printing the variable that is in the vector

    for (int i = 0; i < C; i++) {

        print_half_width();

        cout << collection[row - 1][i];

        print_half_width();

        cout << "║";
    }

    cout << endl;
}

// A function to print a row that divides the grid boxes

void print_bar_row() {
    cout << "  ╠";

    for (int i = 0; i < C - 1; i++) {

        print_full_bar();

        cout << "╬";
    }

    print_full_bar();
    cout << "╣";

    cout << endl;
}

// A function to print the bottom line of the grid

void print_bottom_line() {

    cout << "  ╚";

    for (int i = 0; i < C - 1; i++) {

        print_full_bar();

        cout << "╩"; 
    }

    print_full_bar();

    cout << "╝" << endl;
}

int main() {

    // Declare the col and row integer variables
    // These are used for each user input

    int col;
    int row;

    // Declare a vector of vectors of strings
    // This holds the current state of the grid box values

    vector< vector<string> > collection;
    
    // Expand the number of string-vectors within the main vector to account for the number of rows on the grid

    collection.resize(R);

    // Set a default column value of "." for each of the <C> number of grid boxes

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            collection[i].push_back(".");
        }
    }

    // Initiate an endless while loop to draw and redraw the current grid to the screen
    // and to listen for user input/updates

    while (true) {

        // Clear the terminal

        cout << "\033[2J\033[1;1H";

        // Draw the current state of the grid

        print_top_line();

        for (int i = 0; i < R; i++) {
            print_fill_row();
            print_var_row(i + 1, collection);
            print_fill_row();
            if (i != R - 1) {
                print_bar_row();
            } 
        }

        print_bottom_line();
        cout << endl;

        // Ensure the col and row variables are reset to 0 for this iteration of the endless while loop

        col = 0;
        row = 0;

        // Declare variables to query whether or not the user has entered a valid row/column number

        bool col_viable = false;
        bool row_viable = false;

        // Initiate a while loop to listen for user input until a valid column number is entered

        while (!col_viable) {

            // Request user input

            cout << "Enter the number of the column you would like to fill: ";
            cin >> col;

            // Test whether user input is valid, and if not repeat the request for user input
            // Otherwise, update the col_viable variable to allow while loop to end

            if (cin.fail() || col == 0 || C < col) {
                cin.clear();
                cin.ignore(1000, '\n'); 
                cout << "The value you provided is not valid. Please try again." << endl;
            } else if (col < 0) {
                return 0; 
            } else {
                col_viable = true;
            }
        }

        // Initiate a while loop to listen for user input until a valid row number is entered

        while (!row_viable) {

            // Request user input

            cout << "Enter the number of the row you would like to fill: ";
            cin >> row;

            // Test whether user input is valid, and if not repeat the request for user input
            // Otherwise, update the row_viable variable to allow while loop to end

            if (cin.fail() || row == 0 || R < row) {
                cin.clear();
                cin.ignore(1000, '\n'); 
                cout << "The value you provided is not valid. Please try again." << endl;
            } else if (row < 0) {
                return 0;
            } else {
                row_viable = true;
            }
        }

        // At the provided user row and column, update the vector-vector value to 'X'

        collection[row - 1][col - 1] = 'X';

    }

    return 0;
}
