/**
 * rice.cpp
 * CS 201
 * Bryan Beus
 * September 15, 2019
 * A program to display the power of compound interest and to observe the output in various variable types
 */

#include <iostream>
#include <string>
#include <vector>

// Define the Width of the blank spaces in the cells
// This must be an even number

#define Width 6

// Clear the console

void clearConsole();

// Wait for the user to indicate that they are ready to continue

void waitForContinue();

// Set a default function to print a series of blank spaces of length <Width>

void print_full_width(int longest_length, int col_type);

// Set a default function to print a series of blank spaces of half of length <Width>

void print_half_width();

// Set a default function to print a series of double bars of length <Width>

void print_full_bar(int longest_length, int col_type);

// Print the top of the grid

void print_top_line(int longest_length);

// Fill a whole row that has no variables or grid corners

void print_fill_row(int longest_length);

// Fill a row that has variables, including row numbers and variables inside the grid boxes
// Row requires both the current row to print and a vector that has the current state of grid boxes (X's or .'s)

void printSquare(int & currentSquare);

// Print a row that will have at least one variable value on it. 

void print_var_row(int & currentSquare, int & longest_length, std::vector<std::string> & current_total_string);

// Print the bottom line of the grid

void print_bottom_line(int & longest_length);

// Print the current square

void printCurrentSquare(int & currentSquare, std::vector<std::string> & current_total_string);

// Calculate new values for each important value

void calculateNewValues(int & total_in_int, double & total_in_double, unsigned long long int & total_in_long, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, int & square_int_tripped, int & square_double_tripped);

// Create a vector of strings that represent the current state of the variables
// This helps in formatting the GUI table

void createTotalString(std::vector<std::string> & current_total_string, int & total_in_int, double & total_in_double, unsigned long long int & total_in_long);

// Print the measurements for the challenge questions

void printMeasurements(int & currentSquare, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, std::vector<int> & values_met_int,  std::vector<double> & values_met_double, int & square_int_tripped, int & square_double_tripped, int & total_in_int, double & total_in_double);

int main(int argc, char **argv) {

    // Declare the variables that represent the grains of rice on a single square for the currently calculated square

    int total_in_int = 1;
    double total_in_double = 1;
    unsigned long long int total_in_long = 1;

    // Declare a vector to hold the string representation of the digital values
    // This is useful for formatting purposes

    std::vector<std::string> current_total_string;
    
    // Declare variables to represent the sum total of all grains of rice collected

    int full_total_in_int = total_in_int;
    double full_total_in_double = total_in_double;
    unsigned long long int full_total_in_long = total_in_long;

    // Declare vectors to track the square numbers at which our challenge questions are met

    std::vector<int> values_met_int;
    for (int i = 0; i < 3; i++) {
        values_met_int.push_back(0);
    }

    std::vector<double> values_met_double;
    for (int i = 0; i < 3; i++) {
        values_met_double.push_back(0);
    }

    // Declare variables to check when a value type might fail to keep up with the total numbers

    int square_int_tripped = 0;
    int square_double_tripped = 0;

    // Declare variables to track the current square and total

    int currentSquare = 1;
    int totalSquares = 64;

    // Clear the console before we begin

    clearConsole();

    // Initiate a while loop for all calculations and displays

    while (currentSquare <= totalSquares) {

        // Call the createTotalString function to create the string representations of our grains of rice on the current square

        createTotalString(current_total_string, total_in_int, total_in_double, total_in_long);

        // Display the current square

        printCurrentSquare(currentSquare, current_total_string);

        // Print the measurements that track our challenge questions 

        printMeasurements(currentSquare, full_total_in_int, full_total_in_double, full_total_in_long, values_met_int, values_met_double, square_int_tripped, square_double_tripped, total_in_int, total_in_double); 

        // Wait for the user to indicate they are ready to proceed to the next square

        waitForContinue();

        // Clear the console before proceeding
        clearConsole();

        // Calculate the values for the next square

        calculateNewValues(total_in_int, total_in_double, total_in_long, full_total_in_int, full_total_in_double, full_total_in_long, square_int_tripped, square_double_tripped);

        // Increase our total square count

        ++currentSquare;
    }

    return 0;
}

// Clear the console

void clearConsole() {

    std::cout << "\033[2J\033[1;1H";

}

// Wait for the user to indicate that they are ready to continue

void waitForContinue() {

    std::cout << std::endl << "Press enter to continue...";
    getchar();
}

// Set a default function to print a series of blank spaces of length <Width>

void print_full_width(int longest_length, int col_type) {

    // If the column is on the left, print a Width-wide row of blank spaces

    if (col_type == 0) {
        for (int i = 0; i < Width; i++) {
            std::cout << " ";
        }

    // If the column is on the right, print a row of blank spaces that appropriately matches the length of the longest number of grains of rice

    } else if (col_type == 1)
        for (int i = 0; i < longest_length + (Width * 2 / 3); i++) {
            std::cout << " ";
    }
}

// Set a default function to print a series of blank spaces of half of length <Width>

void print_half_width() {
    for (int j = 0; j < (Width * 1 / 3); j++) {
        std::cout << " ";
    }
}

// Set a default function to print a series of double bars of length <Width>

void print_full_bar(int longest_length, int col_type) {

    // If the column is on the left, print a bar of Width length

    if (col_type == 0) {
        for (int i = 0; i < Width; i++) {
            std::cout << "═";
        }

    // If the column is on the right, print a bar of a length appropriate for the longest number of grains of rice

    } else if (col_type == 1)
        for (int i = 0; i < longest_length + (Width * 2 / 3); i++) {
            std::cout << "═";
    }
}

// Print the top of the grid

void print_top_line(int longest_length) {

    // Vertically clear at least one line in the terminal, then print the <Width> blank spaces

    std::cout << std::endl;

    // Print the top row of the grid

    std::cout << "  ╔";

    print_full_bar(longest_length, 0);

    std::cout << "╦";

    print_full_bar(longest_length, 1);

    std::cout << "╗" << std::endl;
}

// Fill a whole row that has no variables or grid corners

void print_fill_row(int longest_length) {

    // Print a divider bar with some formatting spaces

    std::cout << "  ║";

    // Call the print_full_width() function to print the left column 

    print_full_width(longest_length, 0);

    // Print a divider bar

    std::cout << "║";

    // Call the print_full_width() function to print the right column 

    print_full_width(longest_length, 1);

    // Print a divider bar

    std::cout << "║" << std::endl;

}

// Fill a row that has variables, including row numbers and variables inside the grid boxes

void printSquare(int & currentSquare) { 

    // Call default function to print half width of spaces

    print_half_width();

    // If the current square number is less than 10, add an extra space for formatting 

    if (currentSquare < 10) {
        std::cout << " ";
    }

    // Print the current square number 

    std::cout << currentSquare;

    // Call default function to print half width of spaces

    print_half_width();


}

// Print a row in the rice/square GUI element that has variables on it

void print_var_row(int & currentSquare, int & longest_length, std::vector<std::string> & current_total_string) {

    // Iterate through each of the rows

    for (int i = 0; i < 3; i++) {

        // Print the first divider bar

        std::cout << "  ║";

        // If this is the second row, print the square number

        if (i == 1) {
            printSquare(currentSquare); 

        // Otherwise, keep the first column blank

        } else { 
            print_full_width(longest_length, 0);
        }

        // Divider bar

        std::cout << "║";

        // Print a bit of extra space for formatting, before printing rice grain numbers

        print_half_width();

        // Check how many blank spaces are needed to keep the current number in sync with the format of the grid

        int num_spaces = longest_length - current_total_string.at(i).length();

        // Print the number of grains of rice, and the necessary blank spaces for formatting
        std::cout << current_total_string.at(i) << std::string(num_spaces, ' '); 

        // Print some more padding 

        print_half_width();

        // Final divider bar

        std::cout << "║" << std::endl;
    }

}

// Print the bottom line of the grid

void print_bottom_line(int & longest_length) {

    // Print bottom corner

    std::cout << "  ╚";

    // Print a full bar of appropriate length for left column

    print_full_bar(longest_length, 0);

    // Print divider

    std::cout << "╩";

    // Print a full bar of appropriate length for right column
 
    print_full_bar(longest_length, 1);

    // Print right bottom corner

    std::cout << "╝" << std::endl;
}

// Print the current square number, with the appropriate number of empty spaces around it

void printCurrentSquare(int & currentSquare, std::vector<std::string> & current_total_string) {

    // Calculate the longest length of the three records

    int longest_length = current_total_string.at(0).length();

    for (int i = 1; i < current_total_string.size(); i++) {

        if (longest_length < current_total_string.at(i).length()) {
            longest_length = current_total_string.at(i).length();
        }
    } 
    
    // Print first rows of grid

    print_top_line(longest_length);
    print_fill_row(longest_length);

    // Print the variable rows

    print_var_row(currentSquare, longest_length, current_total_string);

    // the bottom rows of grid

    print_fill_row(longest_length);
    print_bottom_line(longest_length);

}

// Calculate new values for each of the important variables; Call this function after printing the current variables to the console

void calculateNewValues(int & total_in_int, double & total_in_double, unsigned long long int & total_in_long, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, int & square_int_tripped, int & square_double_tripped) {

    // Double the current values of grains of rice on the square 

    total_in_int = 2 * total_in_int;
    total_in_double = 2 * total_in_double;
    total_in_long = 2 * total_in_long;

    // While ensuring that we're not adding negatives or zeros (should the size increase beyond capacity), add the current square's rice to the running total for each variable type

    if (total_in_int >= 1) {
        full_total_in_int = full_total_in_int + total_in_int;
    }

    if (total_in_double >= 1) {
        full_total_in_double = full_total_in_double + total_in_double;
    }

    if (total_in_long >= 1) {
        full_total_in_long = full_total_in_long + total_in_long;
    }

}

// Create a string that can visually represent the state of the current square's grains of rice count
// This is useful for formatting

void createTotalString(std::vector<std::string> & current_total_string, int & total_in_int, double & total_in_double, unsigned long long int & total_in_long) {

    // Clear the current_total_string vector

    current_total_string.clear();

    // Add in the new numbers as strings

    current_total_string.push_back(std::to_string(total_in_int));
    current_total_string.push_back(std::to_string(total_in_double));
    current_total_string.push_back(std::to_string(total_in_long));

}

// Print the current measurements that answer the challenge questions

void printMeasurements(int & currentSquare, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, std::vector<int> & values_met_int,  std::vector<double> & values_met_double, int & square_int_tripped, int & square_double_tripped, int & total_in_int, double & total_in_double) {

    // For each data type and for each of the three standards that we want to measure in the challenge questions, check to see whether or not we have surpassed that number of grains of rice
    // If we have, add this value to our vector that tracks the square on which this event occurs

    if (full_total_in_int >= 1000 && values_met_int.at(0) == 0) {

        values_met_int.at(0) = currentSquare;
    }

    if (full_total_in_int >= 1000000 && values_met_int.at(1) == 0) {
        values_met_int.at(1) = currentSquare;
    }

    if (full_total_in_int >= 1000000000 && values_met_int.at(2) == 0) {
        values_met_int.at(2) = currentSquare;
    }

    if (full_total_in_double >= 1000 && values_met_double.at(0) == 0) {

        values_met_double.at(0) = currentSquare;
    }

    if (full_total_in_double >= 1000000 && values_met_double.at(1) == 0) {
        values_met_double.at(1) = currentSquare;
    }

    if (full_total_in_double >= 1000000000 && values_met_double.at(2) == 0) {
        values_met_double.at(2) = currentSquare;
    }

    // Add an extra space for formatting

    std::cout << std::endl;

    // Print the running total of grains of rice, according to the int data type

        std::cout << "Int: Total Grains of Rice Collected:                 " << full_total_in_int << std::endl;

    // For the int data type, for each of the three standards we measure, when they occur print them to the console

    if (values_met_int.at(0) > 0) {
        std::cout << "Int: 1000 Grains of Rice Reached on Square:          " << values_met_int.at(0) << std::endl;
    }

    if (values_met_int.at(1) > 0) {
        std::cout << "Int: 1000000 Grains of Rice Reached on Square:       " << values_met_int.at(1) << std::endl;
    }

    if (values_met_int.at(2) > 0) {
        std::cout << "Int: 1000000000 Grains of Rice Reached on Square:    " << values_met_int.at(2) << std::endl << std::endl;
    }

    // Add an extra space for formatting
    
    std::cout << std::endl;

    // Print the running total of grains of rice, according to the double data type

        std::cout << "Double: Total Grains of Rice Collected:              " << full_total_in_double << std::endl;

    // For the double data type, for each of the three standards we measure, when they occur print them to the console

    if (values_met_double.at(0) > 0) {
        std::cout << "Double: 1000 Grains of Rice Reached on Square:       " << values_met_double.at(0) << std::endl;
    }

    if (values_met_double.at(1) > 0) {
        std::cout << "Double: 1000000 Grains of Rice Reached on Square:    " << values_met_double.at(1) << std::endl;
    }

    if (values_met_double.at(2) > 0) {
        std::cout << "Double: 1000000000 Grains of Rice Reached on Square: " << values_met_double.at(2) << std::endl << std::endl;
    }

    // Add an extra space for formatting

    std::cout << std::endl;

    // Print the running total in the long data type

        std::cout << "Long: Total Grains of Rice Collected:                " << full_total_in_long << std::endl;

    // When we reach the end of all calculations, print our result in the console

    if (currentSquare == 64) {
        std::cout << "The above value is the total of all grains of rice on all squares." << std::endl;
    }

    // Add an extra space for formatting

    std::cout << std::endl;

    // Calculate the square on which the int or the double data type may stop keeping up with our running total

    if (square_int_tripped == 0 && total_in_int <= 0) {
        square_int_tripped = currentSquare;
    }

    if (square_double_tripped == 0 && total_in_double <= 0) {
        square_double_tripped = currentSquare;
    }

    // Report the square on which any failed data type experienced the failure 

    if (square_int_tripped != 0) {

        std::cout << "The int value tripped on square: " << square_int_tripped << std::endl;
    }

    if (square_double_tripped != 0) {

        std::cout << "The double value tripped on square: " << square_int_tripped;
    }

}

