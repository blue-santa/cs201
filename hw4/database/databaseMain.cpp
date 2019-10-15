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

// #include "database.hpp"

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

void selectChapter(vector< vector<string> > &taoTeChing);

void addLine(vector< vector<string> > &taoTeChing);

void updateLine(vector< vector<string> > &taoTeChing);

void deleteLine(vector< vector<string> > &taoTeChing);

void waitForContinue();

// Clear the console 
void clearConsole();

bool createRecord(vector< vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine, string &desiredContent);

bool readRecord(vector < vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine);

void printChapter(int &desiredChapter, const vector< vector<string> > taoTeChing);

bool loadDatabase(vector< vector<string> > &taoTeChing);

int displayOptions(int & option);

int main(int argc, char **argv) {

	// Create empty vector<vector> to serve as database
	vector<vector <string> > taoTeChing (81);

	bool databaseLoaded = loadDatabase(taoTeChing); 

	if (!databaseLoaded)
		return 0;

	waitForContinue(); 

	while (true) {
		int option;

		option = displayOptions(option);

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

	    if (!instream) {
		cin.clear();
		cin.ignore(1000, '\n');
		continue;
	    } else {
		break;
	    }
	}

	// Return user input
	return option; 
}

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

void selectChapter(vector< vector<string> > &taoTeChing) {
    clearConsole();
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select your chapter: ";

    int desiredChapter;

    while (true) {
        string line;

        getline(cin, line);
        istringstream instream(line);

        instream >> desiredChapter;

        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    desiredChapter--;

    printChapter(desiredChapter, taoTeChing);

    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();
}

void addLine(vector< vector<string> > &taoTeChing) { 
    clearConsole();
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter to which you would like to add a line:  ";

    int desiredChapter; 

    while (true) {
        string line;
        getline(cin, line);

        istringstream instream(line);

        instream >> desiredChapter;

        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    desiredChapter--;

    printChapter(desiredChapter, taoTeChing);
    cout << endl;

    int desiredLine = taoTeChing[desiredChapter].size();

    cout << "What is the line you would like to add? ";

    string desiredContent;

    while (true) {
        getline(cin, desiredContent); 

        if (!cin || cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please try again: ";
        } else {
            break;
        }
    }

    createRecord(taoTeChing, desiredChapter, desiredLine, desiredContent);

    clearConsole();
    cout << "The chapter is now as follows: " << endl;

    printChapter(desiredChapter, taoTeChing);
    
    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();

}

void updateLine(vector< vector<string> > &taoTeChing) { 
    clearConsole();
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter to update:  ";

    int desiredChapter;

    while (true) {
        string line;
        getline(cin, line);

        istringstream instream(line);

        instream >> desiredChapter;

        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    desiredChapter--;

    printChapter(desiredChapter, taoTeChing);
    cout << endl;

    size_t chapterLimit = taoTeChing[desiredChapter].size();

    cout << "Which line would you like to edit? ";

    int desiredLine;

    while (true) {
        string line;
        getline(cin, line);

        istringstream instream(line); 
        instream >> desiredLine;

        if (!instream || desiredLine < 1 || desiredLine > chapterLimit) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    desiredLine--;

    cout << endl;

    cout << "What would you like the line to say? " << endl;

    string desiredContent;

    while (true) {
        getline(cin, desiredContent);

        if (!cin || cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    createRecord(taoTeChing, desiredChapter, desiredLine, desiredContent);

    cout << "The chapter is now as follows: " << endl;

    printChapter(desiredChapter, taoTeChing);

    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();
}

void deleteLine(vector< vector<string> > &taoTeChing) {
    clearConsole();
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter from which to delete a line:  ";

    int desiredChapter;

    while (true) {
        string line;
        getline(cin, line);

        istringstream instream(line);
        instream >> desiredChapter;

        if (!instream || desiredChapter > 81 || desiredChapter < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    desiredChapter--;

    printChapter(desiredChapter, taoTeChing);
    cout << endl;

    size_t chapterLimit = taoTeChing[desiredChapter].size();

    cout << "Which line would you like to delete? ";
    int desiredLine;

    while (true) {
        string line;
        getline(cin, line);

        istringstream instream(line);

        instream >> desiredLine;

        if (!instream || desiredLine > chapterLimit || desiredLine < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }
    --desiredLine;

    cout << endl;

    taoTeChing[desiredChapter].erase(taoTeChing[desiredChapter].begin() + desiredLine);

    cout << "The chapter is now as follows: " << endl;

    printChapter(desiredChapter, taoTeChing);

    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();
}

void waitForContinue() {

    cout << endl << "Press enter to continue...";
    getchar();
}

// Clear the console 
void clearConsole() {

    // Clear the console 
    cout << "\033[2J\033[1;1H";

}

bool createRecord(vector< vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine, string &desiredContent) {
    size_t chapterActualSize = taoTeChing[desiredChapter].size();

    if (desiredLine >= chapterActualSize) { 
       taoTeChing[desiredChapter].push_back(desiredContent); 
       cout << endl;
    } else {
        taoTeChing[desiredChapter][desiredLine] = desiredContent; 
    }

    return true;
}

bool readRecord(vector < vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine) {

    cout << taoTeChing[desiredChapter].at(desiredLine) << endl;

    return true;
}

void printChapter(int &desiredChapter, const vector< vector<string> > taoTeChing) { 

    cout << "Chapter " << desiredChapter + 1 << endl;
    cout << endl;

    for (size_t i {0}; i < taoTeChing[desiredChapter].size(); i++) {

        if (i + 1 < 10)
            cout << " " << i + 1;
        else
            cout << i + 1;

        cout << "  " <<  taoTeChing[desiredChapter].at(i) << endl;
    }

    cout << endl;
    cout << endl; 
}

