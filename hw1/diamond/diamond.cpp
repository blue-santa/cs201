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

    int two_times = num_lines * 2;

    int pos_ver = 0;
    string current_line;

    while (pos_ver < num_lines) {
        
        current_line = "";

        for (int i = 0; i <= two_times; i++) {
            if (
                    (
                        (num_lines - pos_ver <= i && i <= num_lines) ||
                        (num_lines <= i && i <= num_lines + pos_ver)
                    )
                    && pos_ver <= num_lines
               )
            {
                current_line = current_line + "#";
            } else {
                current_line = current_line + "a";
            }

            // stopping here
        }

        cout << current_line << endl;

        pos_ver += 1;
    }

    while (pos_ver < two_times) {

        current_line = "";

        for (int i = 0; i <= two_times; i++) {
            if (
                    (
                        (pos_ver <= i + num_lines && i <= num_lines) ||
                        (num_lines <= i && i <= two_times - pos_ver)
                    )
               )
            {
                current_line = current_line + "#";
            } else {
                current_line = current_line + "a";
            }
        }

        cout << current_line << endl;

        pos_ver += 1;

    }

    return 0;
}
