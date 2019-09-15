/** 
 * main.cpp
 * Bryan Beus
 * September 14, 2019
 * The main program in the assignment - vector names and other features
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// We use the boost library for hashing names

#include <boost/functional/hash.hpp>

// Store name inputs from the user
// The names variable is declared in the main scope

void InputNames(std::vector<std::string> & names) {

    // Request 10 names from the user using a for loop

    for (int i = 0; i < 10; i++) {

        std::string name;
        std::cout << "Please enter a name: ";
        std::getline (std::cin, name);

        // Place each name in the main scope's names vector

        names.push_back(name);
    }
}

// Wait for the user to indicate that they are ready to continue

void waitForContinue() {

    std::cout << std::endl << "Press enter to continue...";
    getchar();
}

// Clear the console

void clearConsole() {

        // Clear the console

        std::cout << "\033[2J\033[1;1H";

}

// Check whether a user-provided name exists within the names data

bool DoesNameExist(const std::vector<std::string> & names) {

    // Declare and store the user-provided name

    std::string nameToFind;
    std::cout << "Tell me a name for which to search in the database: ";
    std::getline (std::cin, nameToFind);

    // Iterate through the names data to see if the name exists
    for (int i = 0; i < names.size(); i++) {
        if (names.at(i) == nameToFind) {

            // If the name does exist, indicate this in the console and return true

            std::cout << "Yes, the name, " << nameToFind << ", is in the data table." << std::endl;
            return true;
        }
    }

    // If the name does not exist, then indicate this in the console and return false

    std::cout << "No, this name is not in the database." << std::endl;
    return false;
}

// Find the length of the longest name of the data

int getLongestNameLength(const std::vector<std::string> & names) {

    // Test that there is at least one name provided in the names data

    if (names.size() < 1) {
        std::cout << "Warning: There are no names in the data." << std::endl;
        return 0;
    }

    // Declare the variable and initiate it at the first vector value

    int longest_length = names.at(0).length();

    // Iterate through the names data
    // If any name is longer than the first name, update the variable to the new longest length

    for (int i = 0; i < names.size(); i++) {

        if (longest_length < names.at(i).length()) {
            longest_length = names.at(i).length();
        }
    }

    // Return the longest length

    return longest_length;
}

// Iterate through the names data and print each name to the console

void PrintNames(const std::vector<std::string> & names) {

    // Indicate the stage of the function to the user in the console

    std::cout << "The following names are in the database: " << std::endl << std::endl;

    // Print each name in the names vector

    for (int i = 0; i < names.size(); i++) {

        std::cout << names.at(i) << std::endl;
    }

}

// Create a hash of each name in the names data, place the hash into a table, and return for later use

std::vector<std::size_t> CreateHashData(const std::vector<std::string> & names) {

    // Declare the hash table

    std::vector<std::size_t> hash_table;

    // For each name in names, use the boost library to create a hash and place it into the table

    for (int i = 0; i < names.size(); i++) {
        boost::hash<std::string> string_hash;
        std::size_t hashed_name = string_hash(names.at(i));
        hash_table.push_back(hashed_name);
    }

    // Return the hash_table variable

    return hash_table;

}

// Print the names and the associated name hashes in the data

void PrintNameHashes(const std::vector<std::size_t> & hash_table, const std::vector<std::string> & names) {

    // State in the console what the function does

    std::cout << "The following hashes belong respectively to the names in the names vector." << std::endl << std::endl;

    // Declare a longest_length varaible and use the getLongestNameLength() function to create a universal target length of spaces " "

    int longest_length = getLongestNameLength(names);

    // Iterate through the names and hashes and print them to the table
    for (int i = 0; i < hash_table.size(); i++) { 
        
        // Declare the target number of spaces, given the format for the console output
        // Add 3 units of spaces onto the variable, for good measure

        int num_spaces = longest_length + 3 - names.at(i).length();

        // Print the names, num_spaces spaces between, and the hashes

        std::cout << names.at(i) << ":" << std::string(num_spaces, ' ') << hash_table.at(i) << std::endl;
    }

} 

int main(int argc, char **argv) {

    // Clear the console

    clearConsole();

    // Declare a names variable to serve throughout the program

    std::vector<std::string> names;
    
    // Call the InputNames() function to request the user to provide names

    InputNames(names);

    // Wait for user permission to continue
    
    waitForContinue();

    // Clear the console

    clearConsole();

    // Call the DoesNameExist() function to request the user to search for a name
    // Return the result to a new bool varaible, in case the use would come in handy later

    bool result_of_name_search = DoesNameExist(names);

    // Wait for user permission to continue
    
    waitForContinue();

    // Clear the console

    clearConsole();

    // Call the PrintNames() function to print names to the console

    PrintNames(names);

    // Create a vector variable with hashes of the names using the CreateHashData() function

    std::vector<std::size_t> hash_table = CreateHashData(names);

    // Wait for user permission to continue
    
    waitForContinue();

    // Clear the console

    clearConsole();

    // Use the PrintNameHashes() function to print all names and hashes to the console
    PrintNameHashes(hash_table, names);

    // Wait for user permission to continue
    
    waitForContinue();

    // Clear the console

    clearConsole();

    // End

    return 0;

}
