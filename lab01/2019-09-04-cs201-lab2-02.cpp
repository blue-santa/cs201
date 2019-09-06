/**
 * CS201 Lab01
 * Bryan Beus
 * 4 Sept 2019
 * Lab 01 for CS 201
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int day;
    int month;
    int year;

    cout << "Please provide the day of your date of birth as an integer: ";
    cin >> day;

    cout << "Please provide the month of your date of birth as an integer: ";
    cin >> month;


    cout << "Please provide the year of your date of birth as an integer: ";
    cin >> year;


    cout << "The result is: " << month << "/" << day << "/" << year << endl;

    return 0;
}
