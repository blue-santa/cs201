/**
 * money.cpp
 * Bryan Beus
 * September 14, 2019
 * A program to count the money a user has and to return a clean summation of the value
 */

#include <iostream>
#include <string>
#include <vector>

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

void askUserAgain() {

    std::cout << "You provided an invalid input. Please try again." << std::endl << std::endl;;

}

void queryUserWallet(std::vector<int> & user_wallet, std::vector<std::string> & coin_list_plural) {

    int input;


    for (int i = 0; i < coin_list_plural.size(); i++) {

        clearConsole();

        std::cout << "In the array there are: " << coin_list_plural.size() << std::endl;

        std::cout << "How many " << coin_list_plural.at(i) << " do you have? ";

        while (true) {

            std::cin >> input;

            if (std::cin.fail() || input < 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                askUserAgain();
                waitForContinue();

            } else {
               user_wallet.push_back(input);
               std::cin.clear();
               std::cin.ignore(1000, '\n');
               break;
            }
        } 
    } 
}

float calculateWalletTotal(std::vector<int> & user_wallet) {

    float total_wallet = 0;

    std::vector<int> values;
        values.push_back(1);
        values.push_back(5);
        values.push_back(10);
        values.push_back(25);

    for (int i = 0; i < 4; i++) {
        total_wallet = total_wallet + user_wallet.at(i) * values.at(i);
    }

    total_wallet = total_wallet * 0.01;
    return total_wallet;
}

void reportWalletSum(std::vector<int> & user_wallet, std::vector<std::string> & coin_list_plural, std::vector<std::string> & coin_list_singular) {

    clearConsole();

    float total_wallet = calculateWalletTotal(user_wallet);

    for (int i = 0; i < 4; i++) {

        std::cout << "You have " << user_wallet.at(i) << " ";

        if (user_wallet.at(i) == 1) {
            std::cout << coin_list_singular.at(i);
        } else {
            std::cout << coin_list_plural.at(i);
        }

        std::cout << "." << std::endl << std::endl;

    }

    std::cout << "The value of all your coins is $" << total_wallet << std::endl; 

    waitForContinue();

}

int main(int argc, char **argv) {

    clearConsole();

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

    queryUserWallet(user_wallet, coin_list_plural);

    clearConsole();

    reportWalletSum(user_wallet, coin_list_plural, coin_list_singular);

    return 0;
}
