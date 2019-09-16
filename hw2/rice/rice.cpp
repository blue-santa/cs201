/**
 * rice.cpp
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
    if (col_type == 0) {
        for (int i = 0; i < Width; i++) {
            std::cout << "═";
        }

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

// A function to fill a whole row that has no variables or grid corners

void print_fill_row(int longest_length) {

    std::cout << "  ║";

    print_full_width(longest_length, 0);

    std::cout << "║";

    print_full_width(longest_length, 1);

    std::cout << "║" << std::endl;

}

// A function to fill a row that has variables, including row numbers and variables inside the grid boxes
// Row requires both the current row to print and a vector that has the current state of grid boxes (X's or .'s)

void printSquare(int & currentSquare) { 

        print_half_width();

        if (currentSquare < 10) {
            std::cout << " ";
        }

        std::cout << currentSquare;

        print_half_width();

}

void print_var_row(int & currentSquare, int & longest_length, std::vector<std::string> & current_total_string) {

    for (int i = 0; i < 3; i++) {

        std::cout << "  ║";

        if (i == 1) {
            printSquare(currentSquare); 
        } else { 
            print_full_width(longest_length, 0);
        }

        std::cout << "║";

        print_half_width();

        int num_spaces = longest_length - current_total_string.at(i).length();

        std::cout << current_total_string.at(i) << std::string(num_spaces, ' '); 

        print_half_width();

        std::cout << "║" << std::endl;
    }

}

// A function to print the bottom line of the grid

void print_bottom_line(int & longest_length) {

    std::cout << "  ╚";

    print_full_bar(longest_length, 0);

    std::cout << "╩";

    print_full_bar(longest_length, 1);

    std::cout << "╝" << std::endl;
}

int calculateLongestLength(std::vector<std::string> & current_total_string, int longest_length) {

}

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
    // Declare a var to keep track of the current row

    print_var_row(currentSquare, longest_length, current_total_string);

    // the bottom rows of grid

    print_fill_row(longest_length);
    print_bottom_line(longest_length);

}

void calculateNewValues(int & total_in_int, double & total_in_double, unsigned long long int & total_in_long, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, int & square_int_tripped, int & square_double_tripped) {

    total_in_int = 2 * total_in_int;
    total_in_double = 2 * total_in_double;
    total_in_long = 2 * total_in_long;

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

void createTotalString(std::vector<std::string> & current_total_string, int & total_in_int, double & total_in_double, unsigned long long int & total_in_long) {

    // Clear the current_total_string vector
    current_total_string.clear();

    // Add in the new numbers as strings

    current_total_string.push_back(std::to_string(total_in_int));
    current_total_string.push_back(std::to_string(total_in_double));
    current_total_string.push_back(std::to_string(total_in_long));

}

void printMeasurements(int & currentSquare, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, std::vector<int> & values_met_int,  std::vector<double> & values_met_double, int & square_int_tripped, int & square_double_tripped, int & total_in_int, double & total_in_double) {

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

    std::cout << std::endl;

        std::cout << "Int: Total Grains of Rice Collected:                 " << full_total_in_int << std::endl;

    if (values_met_int.at(0) > 0) {
        std::cout << "Int: 1000 Grains of Rice Reached on Square:          " << values_met_int.at(0) << std::endl;
    }

    if (values_met_int.at(1) > 0) {
        std::cout << "Int: 1000000 Grains of Rice Reached on Square:       " << values_met_int.at(1) << std::endl;
    }

    if (values_met_int.at(2) > 0) {
        std::cout << "Int: 1000000000 Grains of Rice Reached on Square:    " << values_met_int.at(2) << std::endl << std::endl;
    }

    std::cout << std::endl;

        std::cout << "Double: Total Grains of Rice Collected:              " << full_total_in_double << std::endl;

    if (values_met_double.at(0) > 0) {
        std::cout << "Double: 1000 Grains of Rice Reached on Square:       " << values_met_double.at(0) << std::endl;
    }

    if (values_met_double.at(1) > 0) {
        std::cout << "Double: 1000000 Grains of Rice Reached on Square:    " << values_met_double.at(1) << std::endl;
    }

    if (values_met_double.at(2) > 0) {
        std::cout << "Double: 1000000000 Grains of Rice Reached on Square: " << values_met_double.at(2) << std::endl << std::endl;
    }

    std::cout << std::endl;

        std::cout << "Long: Total Grains of Rice Collected:                " << full_total_in_long << std::endl;

    if (currentSquare == 64) {
        std::cout << "The above value is the total of all grains of rice on all squares." << std::endl;
    }

    std::cout << std::endl;

    if (square_int_tripped == 0 && total_in_int <= 0) {
        square_int_tripped = currentSquare;
    }

    if (square_double_tripped == 0 && total_in_double <= 0) {
        square_double_tripped = currentSquare;
    }

    if (square_int_tripped != 0) {

        std::cout << "The int value tripped on square: " << square_int_tripped << std::endl;
    }

    if (square_double_tripped != 0) {

        std::cout << "The double value tripped on square: " << square_int_tripped;
    }

}

int main(int argc, char **argv) {

    int total_in_int = 1;
    double total_in_double = 1;
    unsigned long long int total_in_long = 1;

    int full_total_in_int = total_in_int;
    double full_total_in_double = total_in_double;
    unsigned long long int full_total_in_long = total_in_long;

    int square_int_tripped = 0;
    int square_double_tripped = 0;

    int currentSquare = 1;
    int totalSquares = 64;

    std::vector<int> values_met_int;
    for (int i = 0; i < 3; i++) {
        values_met_int.push_back(0);
    }

    std::vector<double> values_met_double;
    for (int i = 0; i < 3; i++) {
        values_met_double.push_back(0);
    }

    std::vector<std::string> current_total_string;

    clearConsole();

    while (currentSquare <= totalSquares) {

        createTotalString(current_total_string, total_in_int, total_in_double, total_in_long);

        printCurrentSquare(currentSquare, current_total_string);

        printMeasurements(currentSquare, full_total_in_int, full_total_in_double, full_total_in_long, values_met_int, values_met_double, square_int_tripped, square_double_tripped, total_in_int, total_in_double); 

        waitForContinue();

        clearConsole();

        calculateNewValues(total_in_int, total_in_double, total_in_long, full_total_in_int, full_total_in_double, full_total_in_long, square_int_tripped, square_double_tripped);

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
    if (col_type == 0) {
        for (int i = 0; i < Width; i++) {
            std::cout << "═";
        }

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

// A function to fill a whole row that has no variables or grid corners

void print_fill_row(int longest_length) {

    std::cout << "  ║";

    print_full_width(longest_length, 0);

    std::cout << "║";

    print_full_width(longest_length, 1);

    std::cout << "║" << std::endl;

}

// A function to fill a row that has variables, including row numbers and variables inside the grid boxes
// Row requires both the current row to print and a vector that has the current state of grid boxes (X's or .'s)

void printSquare(int & currentSquare) { 

        print_half_width();

        if (currentSquare < 10) {
            std::cout << " ";
        }

        std::cout << currentSquare;

        print_half_width();

}

void print_var_row(int & currentSquare, int & longest_length, std::vector<std::string> & current_total_string) {

    for (int i = 0; i < 3; i++) {

        std::cout << "  ║";

        if (i == 1) {
            printSquare(currentSquare); 
        } else { 
            print_full_width(longest_length, 0);
        }

        std::cout << "║";

        print_half_width();

        int num_spaces = longest_length - current_total_string.at(i).length();

        std::cout << current_total_string.at(i) << std::string(num_spaces, ' '); 

        print_half_width();

        std::cout << "║" << std::endl;
    }

}

// A function to print the bottom line of the grid

void print_bottom_line(int & longest_length) {

    std::cout << "  ╚";

    print_full_bar(longest_length, 0);

    std::cout << "╩";

    print_full_bar(longest_length, 1);

    std::cout << "╝" << std::endl;
}

int calculateLongestLength(std::vector<std::string> & current_total_string, int longest_length) {

}

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
    // Declare a var to keep track of the current row

    print_var_row(currentSquare, longest_length, current_total_string);

    // the bottom rows of grid

    print_fill_row(longest_length);
    print_bottom_line(longest_length);

}

void calculateNewValues(int & total_in_int, double & total_in_double, unsigned long long int & total_in_long, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, int & square_int_tripped, int & square_double_tripped) {

    total_in_int = 2 * total_in_int;
    total_in_double = 2 * total_in_double;
    total_in_long = 2 * total_in_long;

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

void createTotalString(std::vector<std::string> & current_total_string, int & total_in_int, double & total_in_double, unsigned long long int & total_in_long) {

    // Clear the current_total_string vector
    current_total_string.clear();

    // Add in the new numbers as strings

    current_total_string.push_back(std::to_string(total_in_int));
    current_total_string.push_back(std::to_string(total_in_double));
    current_total_string.push_back(std::to_string(total_in_long));

}

void printMeasurements(int & currentSquare, int & full_total_in_int, double & full_total_in_double, unsigned long long int & full_total_in_long, std::vector<int> & values_met_int,  std::vector<double> & values_met_double, int & square_int_tripped, int & square_double_tripped, int & total_in_int, double & total_in_double) {

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

    std::cout << std::endl;

        std::cout << "Int: Total Grains of Rice Collected:                 " << full_total_in_int << std::endl;

    if (values_met_int.at(0) > 0) {
        std::cout << "Int: 1000 Grains of Rice Reached on Square:          " << values_met_int.at(0) << std::endl;
    }

    if (values_met_int.at(1) > 0) {
        std::cout << "Int: 1000000 Grains of Rice Reached on Square:       " << values_met_int.at(1) << std::endl;
    }

    if (values_met_int.at(2) > 0) {
        std::cout << "Int: 1000000000 Grains of Rice Reached on Square:    " << values_met_int.at(2) << std::endl << std::endl;
    }

    std::cout << std::endl;

        std::cout << "Double: Total Grains of Rice Collected:              " << full_total_in_double << std::endl;

    if (values_met_double.at(0) > 0) {
        std::cout << "Double: 1000 Grains of Rice Reached on Square:       " << values_met_double.at(0) << std::endl;
    }

    if (values_met_double.at(1) > 0) {
        std::cout << "Double: 1000000 Grains of Rice Reached on Square:    " << values_met_double.at(1) << std::endl;
    }

    if (values_met_double.at(2) > 0) {
        std::cout << "Double: 1000000000 Grains of Rice Reached on Square: " << values_met_double.at(2) << std::endl << std::endl;
    }

    std::cout << std::endl;

        std::cout << "Long: Total Grains of Rice Collected:                " << full_total_in_long << std::endl;

    if (currentSquare == 64) {
        std::cout << "The above value is the total of all grains of rice on all squares." << std::endl;
    }

    std::cout << std::endl;

    if (square_int_tripped == 0 && total_in_int <= 0) {
        square_int_tripped = currentSquare;
    }

    if (square_double_tripped == 0 && total_in_double <= 0) {
        square_double_tripped = currentSquare;
    }

    if (square_int_tripped != 0) {

        std::cout << "The int value tripped on square: " << square_int_tripped << std::endl;
    }

    if (square_double_tripped != 0) {

        std::cout << "The double value tripped on square: " << square_int_tripped;
    }

}

