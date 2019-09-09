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

    // Declare the variable to hold the number of lines

    int num_lines;

    // Request info about the number of lines

    cout << "Enter the number of lines to print in the diamond: ";

    // Capture user input

    cin >> num_lines;

    // Check to make sure that the input is within our valid parameters

    if (num_lines == 0 || num_lines < 0 || cin.fail()) {

        cout << "The value you entered is not a valid number" << endl;

        return 0;
    } 

    // Set the doubled value of num_lines

    int two_times = num_lines * 2;

    // Set our current vertical position on the diamond grid

    int pos_ver = 0;

    // Declare an empty string to use for additive iteration

    string current_line;

    // Begin while loop to print first half of diamond

    while (pos_ver < num_lines) {

        // Set or reset current_line variable value to empty

        current_line = "";

        // Use iterative adding to the current_line string to build the current line's # output

        for (int i = 1; i < two_times; i++) {

            // Set the equations to decide whether each character in the string should be a " " or a "#"

            if (
                    (num_lines - pos_ver <= i && i <= num_lines) ||
                    (num_lines <= i && i <= num_lines + pos_ver)
               )
            {

                // Add a "#" if the equation produce a true result 

                current_line = current_line + "#";
            } else {

                // Add a space, if not

                current_line = current_line + " ";
            }

        }

        // Print the resulting current_line variable to the terminal

        cout << current_line << endl;

        // Increase our vertical position in preparation to move to the next line

        pos_ver += 1;
    }

    // Because we're creating a diamond, we want to skip the first row, so that we do not get a fully mirrored image in the vertical direction

    pos_ver += 1;

    // Begin while loop for bottom half of diamond

    while (pos_ver < two_times) {

        // Reset current_line value to empty

        current_line = "";

        // Use iterative adding to create the string to print to the console

        for (int i = 1; i < two_times; i++) {

            // Equations to determine whether to add a "#" or a " "

            if (
                    (pos_ver < i + num_lines && i <= num_lines) ||
                    (num_lines <= i && i < two_times - pos_ver + num_lines)
               )
            {

                // Add a "#"

                current_line = current_line + "#";
            } else {

                // Or add a " " 

                current_line = current_line + " ";
            }
        }

        // Print the resulting string to the terminal

        cout << current_line << endl;

        // Increase our vertical position
        pos_ver += 1;

    }

    // End

    return 0;
}
