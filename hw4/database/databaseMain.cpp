/**
 * databaseMain.cpp
 * CS 201
 * Bryan Beus
 * October 14, 2019
 * The main file for database project
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>
#include <chrono>
#include <thread>

#include "database.hpp"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::find;
using std::istringstream;
using std::ifstream;
using std::this_thread::sleep_for;
using std::chrono::nanoseconds;

int main(int argc, char **argv) {

	// Create empty vector<vector> to serve as database
	vector<vector <string> > taoTeChing (81);

    // Load database
	bool databaseLoaded = loadDatabase(taoTeChing); 

    // If the database failed to load, end the program
	if (!databaseLoaded)
		return 0;

    // Allow user to read database call
	waitForContinue(); 

    // Initiate endless while loop to display main menu
	while (true) {

        // Declare option variable to collect user input
        // Display option screen and receive user input
		int option; 
		option = displayOptions(option);

        // Follow user directions to appropriate function
		switch (option) {
		    case 0:
                return 0;
		    case 1:
                selectChapter(taoTeChing);
                break;
		    case 2:
                addLine(taoTeChing);
                break;
		    case 3:
                updateLine(taoTeChing);
                break;
		    case 4:
                deleteLine(taoTeChing);
                break;
		    default:
                break;
		} 
	}
	return 0;
}
