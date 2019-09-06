/**
 * CS201 Lab01
 * Bryan Beus
 * 4 Sept 2019
 * Lab 01 for CS 201
 */

#include <iostream>
#include <string>

int day;
int month;
int year;

using namespace std;

string day_string;
string month_string;
string year_string;

void convert_day() {
    if (day <= 9) {
        day_string = "0" + to_string(day);
    } else {
        day_string = to_string(day);
    }
}

void convert_month() {
    if (month <= 9) {
        month_string = "0" + to_string(month);
    } else {
        month_string = to_string(month);
    }
}

void convert_year() {
    year_string = to_string(year);
}

int main() {
    
    cout << "Please provide the day of your date of birth as an integer: ";
    cin >> day;

    cout << "Please provide the month of your date of birth as an integer: ";
    cin >> month;


    cout << "Please provide the year of your date of birth as an integer: ";
    cin >> year;


    convert_day();
    convert_month();
    convert_year();

    string result = year_string + "-" + day_string + "-" + month_string;

    cout << "The result is: " << result;


    return 0;
}
