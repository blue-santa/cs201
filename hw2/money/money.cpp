/**
 * money.cpp
 * Bryan Beus
 * September 14, 2019
 * A program to count the money a user has and to return a clean summation of the value
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Clear the console

void clearConsole() {

    // Clear the console

    std::cout << "\033[2J\033[1;1H";

}

// Wait for the user to indicate that they are ready to continue

void waitForContinue() {

    std::cout << std::endl << "Press enter to continue...";
    getchar();
}

// Inform the user their input is invalid

void askUserAgain() {

    std::cout << "You provided an invalid input. Please try again." << std::endl << std::endl;;

}

// Query the user to input their wallet state

void queryUserWallet(std::vector<int> & user_wallet, std::vector<std::string> & coin_list_plural) {

    // Declare an input variable for user input

    int input;

    // Request the user to input the total number of each coin they have in their wallet

    for (int i = 0; i < coin_list_plural.size(); i++) {

        clearConsole();

        std::cout << "How many " << coin_list_plural.at(i) << " do you have? ";

        // Initiate a while loop to wait until the user inputs a viable response

        while (true) {

            std::cin >> input;

            // If the response is invalid, ask again

            if (std::cin.fail() || input < 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                askUserAgain();
                waitForContinue();

                // If the response is valid, input the value and move to the next iteration of the for loop

            } else {
               user_wallet.push_back(input);
               std::cin.clear();
               std::cin.ignore(1000, '\n');
               break;
            }
        } 
    } 
}

// Calculate the wallet total as a floating point variable

float calculateWalletTotal(std::vector<int> & user_wallet) {

    float total_wallet = 0;

    // Initiate the various values of the coins

    std::vector<int> values;
        values.push_back(1);
        values.push_back(5);
        values.push_back(10);
        values.push_back(25);

        // Calcuate the total value of the wallet in pennies

    for (int i = 0; i < 4; i++) {
        total_wallet = total_wallet + user_wallet.at(i) * values.at(i);
    }

    // Transform the total value into a dollar value

    total_wallet = total_wallet * 0.01;
    
    // Return the total value

    return total_wallet;
}

// Print to the console the total wallet sum

void reportWalletSum(std::vector<int> & user_wallet, std::vector<std::string> & coin_list_plural, std::vector<std::string> & coin_list_singular) {

    clearConsole();

    // Call the calculateWalletTotal() function to calculate the wallet total

    float total_wallet = calculateWalletTotal(user_wallet);

    // For each coin type, print the total in the user's wallet

    for (int i = 0; i < 4; i++) {

        std::cout << "You have " << user_wallet.at(i) << " ";

        if (user_wallet.at(i) == 1) {
            std::cout << coin_list_singular.at(i);
        } else {
            std::cout << coin_list_plural.at(i);
        }

        std::cout << "." << std::endl << std::endl;

    }

    // Print the total value in the wallet

    std::cout << "The value of all your coins is $" << std::fixed << std::setprecision(2) << total_wallet << std::endl; 

    // Pause for user to continue

    waitForContinue();

}

int main(int argc, char **argv) {

    // Clear the console

    clearConsole();

    // Declare the vector to hold the user's coin totals

    std::vector<int> user_wallet;

    // Create list of plural coin names
    
    std::vector<std::string> coin_list_plural;
        coin_list_plural.push_back("pennies");
        coin_list_plural.push_back("nickels");
        coin_list_plural.push_back("dimes");
        coin_list_plural.push_back("quarters");

    // Create list of singular coin names
    
    std::vector<std::string> coin_list_singular;
        coin_list_singular.push_back("penny");
        coin_list_singular.push_back("nickel");
        coin_list_singular.push_back("dime");
        coin_list_singular.push_back("quarter");

        // Query the user's wallet

    queryUserWallet(user_wallet, coin_list_plural);

    // Clear the console

    clearConsole();

    // Report the total value

    reportWalletSum(user_wallet, coin_list_plural, coin_list_singular);

    return 0;
}
