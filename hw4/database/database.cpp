/**
 * userInput.cpp
 * CS 201
 * Bryan Beus
 * September 30, 2019
 * The function definition file for userInput
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>

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

// Display the options screen
int displayOptions(int &option) {

	// Clear the console
	clearConsole();

	// Display header
	string title = "Welcome to the Tao Te Ching library";
	cout << string(title.length(), '=') << endl;
	cout << title << endl;
	cout << string(title.length(), '=') << endl;
	cout << endl; 
	cout << "This program allows the user to practice CRUD database techniques, with the Tao Te Ching as a reference" << endl; 
	cout << endl;

	// Display menu
	cout << "Please select an option from the following menu: " << endl;
	cout << "1) Select a chapter to read from the Tao Te Ching" << endl;
	cout << "2) Add a line to a specific chapter" << endl;
	cout << "3) Update a line from a specific chapter" << endl;
	cout << "4) Delete a line from a specific chapter" << endl;
	cout << "0) Exit program" << endl;
	cout << endl;

	// Display prompt
	cout << "> ";


	// Read user option input
	while (true) { 
	    string line;
	    getline(cin, line);

	    istringstream instream(line);

	    instream >> option;

        // If input is invalid, restart while loop
	    if (!instream) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;

        // Otherwise, end while loop
	    } else {
            break;
	    }
	}

	// Return user input
	return option; 
}

// Load the database
bool loadDatabase(vector< vector<string> > &taoTeChing) {

	// State filename where initial database is stored
	string filename = "tao_te_ching.txt";
	
	// Load Tao Te Ching filename into stream
	ifstream in(filename);

	// Check that the file loaded properly
	if (!in) {
		cerr << "Cannot open file: " << filename << endl;

		// If the file did not load properly end func and program
		return false;
	}

	// Declare line to hold line-by-line input of file
	string line;

	// Declare Chapter count, to track current chapter
	// Set to -1 so that first iteration increases to index 0
	int chapterCount {-1};

	// Declare lineCount to iterate through each line by count
	int lineCount {0};

	// Initiate while loop; lasts until getline returns false
	while (getline(in, line)) { 

		// Declare istringstream to capture each full line
		istringstream instream(line);

		// Capture firstWord, to test if it is a new Chapter heading
		string firstWord; 
		instream >> firstWord;
		if (firstWord == "Chapter") {

			// If this line is a new chapter, increaes the chapterCount and reset lineCount
			chapterCount++;
			lineCount = 0;
		} else {

			// If the line is a normal line, pass all necessary information to the createRecord function
			createRecord(taoTeChing, chapterCount, lineCount, line);
		}

		// Increase current lineCount
		lineCount++;
	}

	// Clear the console and state that Database was successfully created
	clearConsole();
	cout << "Database created..." << endl;

	// Return true and end func
	return true;
}

// Select a chapter to read
void selectChapter(vector< vector<string> > &taoTeChing) {

    // Clear the console
    clearConsole();

    // Display main prompt
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select your chapter: ";

    // Declare int to hold user's chapter input
    int desiredChapter;

    // Initiate endless while loop to request user input
    while (true) {
        string line; 
        getline(cin, line);
        istringstream instream(line); 
        instream >> desiredChapter;

        // If user input is invalid, restart loop
        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";

        // Otherwise, break loop
        } else {
            break;
        }
    }

    // Reduce user input by one var to account for index value difference
    desiredChapter--;

    // Print the chapter the user desires to read
    printChapter(desiredChapter, taoTeChing);

    // Wait for user to proceed
    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();
}

// Add a line to a user input
void addLine(vector< vector<string> > &taoTeChing) { 

    // Clear the console
    clearConsole();

    // Display main heading
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter to which you would like to add a line:  ";

    // Initiate endless while loop to receive user input for desired Chapter
    int desiredChapter; 
    while (true) {
        string line;
        getline(cin, line); 
        istringstream instream(line); 
        instream >> desiredChapter;

        // If the input is invalid, restart loop
        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";

        // Otherwise, end loop
        } else {
            break;
        }
    }

    // Reduce chapter int by one to account for index value
    desiredChapter--;

    // Print the chapter to the screen for visibility, and print next prompt
    printChapter(desiredChapter, taoTeChing);
    cout << endl; 
    cout << "What is the line you would like to add? ";

    // Set the desired line int to change to the last line, by default, as we are only adding a new line
    int desiredLine = taoTeChing[desiredChapter].size(); 
    
    // Initiate endless while loop to capture user's new line to add
    string desiredContent;
    while (true) {
        getline(cin, desiredContent); 

        // If the input is invalid, restart loop
        if (!cin || cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please try again: ";


        // Otherwise, end loop
        } else {
            break;
        }
    }

    // Create the new line
    createRecord(taoTeChing, desiredChapter, desiredLine, desiredContent); 

    // Clear console and print updated chapter to the screen
    clearConsole();
    cout << "The chapter is now as follows: " << endl; 
    printChapter(desiredChapter, taoTeChing);
    
    // Wait for user to finish reading
    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue(); 
}

// Update an existing line
void updateLine(vector< vector<string> > &taoTeChing) { 

    // Clear console and print next prompt
    clearConsole();
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter to update:  ";

    // Initiate endless while loop to capture user's desired chapter
    int desiredChapter; 
    while (true) {
        string line;
        getline(cin, line); 
        istringstream instream(line); 
        instream >> desiredChapter;

        // If user's response is invalid, restart loop
        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";

        // Otherwise, end loop
        } else {
            break;
        }
    }

    // Reduce desired chapter count to account for index value
    desiredChapter--;

    // Print the chapter and next propmt to be updated to the screen
    printChapter(desiredChapter, taoTeChing);
    cout << endl; 
    cout << "Which line would you like to edit? ";

    // Initiate chapter limit, to limit user responses within existing range
    size_t chapterLimit = taoTeChing[desiredChapter].size();

    // Initiate endless while loop to capture user's desired line
    int desiredLine; 
    while (true) {
        string line;
        getline(cin, line); 
        istringstream instream(line); 
        instream >> desiredLine;

        // If the user input is valid, restart loop
        if (!instream || desiredLine < 1 || desiredLine > chapterLimit) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";

        // Otherwise, break loop
        } else {
            break;
        }
    }

    // Decrease line by one to account for index value
    desiredLine--;

    // Prompt user's desired updates and changes
    cout << endl; 
    cout << "What would you like the line to say? " << endl; 

    // Initiate endless while loop to request user udpates
    string desiredContent; 
    while (true) {
        getline(cin, desiredContent);

        // If user input is invalid, restart loop
        if (!cin || cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";

        // Otherwise, break loop
        } else {
            break;
        }
    }

    // Use user inputs to create new record
    createRecord(taoTeChing, desiredChapter, desiredLine, desiredContent);

    // Print updated values to the screen and wait for user to indicate they are finished 
    cout << "The chapter is now as follows: " << endl; 
    printChapter(desiredChapter, taoTeChing); 
    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();
}

// Delete a line from a chapter
void deleteLine(vector< vector<string> > &taoTeChing) {
    //
    // Clear console and print prompt 
    clearConsole();
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter from which to delete a line:  ";

    // Request user input for desired chapter from which to delete a line
    int desiredChapter; 
    while (true) {
        string line;
        getline(cin, line); 
        istringstream instream(line);
        instream >> desiredChapter;

        // If user input is invalid, restart loop
        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";

        // Otherwise, end the loop
        } else {
            break;
        }
    }

    // Reduce desired chapter to account for index value
    desiredChapter--;

    // Print selected chapter to screen
    printChapter(desiredChapter, taoTeChing);
    cout << endl;

    // Set limit to number of lines in the chapter
    size_t chapterLimit = taoTeChing[desiredChapter].size();

    // Prompt user for line to delete
    cout << "Which line would you like to delete? ";
    int desiredLine; 
    while (true) {
        string line;
        getline(cin, line); 
        istringstream instream(line); 
        instream >> desiredLine;

        // If user input is invalid, restart loop 
        if (!instream || desiredLine > chapterLimit || desiredLine < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";

        // Otherwise, break loop
        } else {
            break;
        }
    }

    // Reduce desired line count to account for index value
    --desiredLine;

    // Remove desired line
    taoTeChing[desiredChapter].erase(taoTeChing[desiredChapter].begin() + desiredLine);

    // Print update to screen and wait for user to finish reading
    cout << endl;
    cout << "The chapter is now as follows: " << endl; 
    printChapter(desiredChapter, taoTeChing); 
    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();
}

// Wait for user response
void waitForContinue() { 
    cout << endl << "Press enter to continue...";
    getchar();
}

// Clear the console 
void clearConsole() {

    // Clear the console 
    cout << "\033[2J\033[1;1H"; 
}

// Create a new record in the database
bool createRecord(vector< vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine, string &desiredContent) {

    // Set actual size of chapter, for monitoring limitations
    size_t chapterActualSize = taoTeChing[desiredChapter].size();

    // If the desired line is not within the existing vector size, create a new line
    if (desiredLine >= chapterActualSize) { 
       taoTeChing[desiredChapter].push_back(desiredContent); 
       cout << endl;

    // Otherwise, set the existing line to the new line and end function
    } else {
        taoTeChing[desiredChapter][desiredLine] = desiredContent; 
    } 
    return true;
}

// Read a given line from the provided vector
bool readRecord(vector < vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine) { 
    cout << taoTeChing[desiredChapter].at(desiredLine) << endl; 
    return true;
}

// Print a full chapter to the console
void printChapter(int &desiredChapter, const vector< vector<string> > taoTeChing) { 

    // Print the header
    cout << "Chapter " << desiredChapter + 1 << endl;
    cout << endl;

    // Iterate through and print each line number
    for (size_t i {0}; i < taoTeChing[desiredChapter].size(); i++) { 
        if (i + 1 < 10)
            cout << " " << i + 1;
        else
            cout << i + 1;

        // Print line
        cout << "  " <<  taoTeChing[desiredChapter].at(i) << endl;
    }

    // Print extra newlines for formatting
    cout << endl;
    cout << endl; 
}

