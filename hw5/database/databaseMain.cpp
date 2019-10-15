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

bool createRecord(vector< vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine, string &desiredContent, bool verbose);

bool readRecord(vector < vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine);

void printChapter(int &desiredChapter, const vector< vector<string> > taoTeChing);

int main(int argc, char **argv) {

    vector<vector <string> > taoTeChing (81);

    string filename = "tao_te_ching.txt";

    // Load Tao Te Ching into database
    ifstream in(filename);

    if (!in) {
        cerr << "Cannot open file: " << filename << endl;
        return 0;
    }

    string line;
    int chapterCount {-1};
    int i {0};

    while (getline(in, line)) {

        istringstream instream(line);
        string firstWord;

        instream >> firstWord;
        if (firstWord == "Chapter") {
            chapterCount++;
            i = 0;
        } else {
            createRecord(taoTeChing, chapterCount, i, line, false);
        }
        i++;
    }

    clearConsole();
    cout << "Database created..." << endl;

    waitForContinue();

    while (true) {
        clearConsole();
        string title = "Welcome to the Tao Te Ching library";
        cout << string(title.length(), '=') << endl;
        cout << title << endl;
        cout << string(title.length(), '=') << endl;
        cout << endl; 
        cout << "This program allows the user to practice CRUD database techniques, with the Tao Te Ching as a reference" << endl;

        cout << endl;
        cout << "Please select an option from the following menu: " << endl;
        cout << "1) Select a chapter to read from the Tao Te Ching" << endl;
        cout << "2) Add a line to a specific chapter" << endl;
        cout << "3) Update a line from a specific chapter" << endl;
        cout << "4) Delete a line from a specific chapter" << endl;
        cout << "0) Exit program" << endl;
        cout << endl;

        cout << "> ";

        int option;
        cin >> option;

        if (cin.fail() || !cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

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

void selectChapter(vector< vector<string> > &taoTeChing) {
    clearConsole();
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select your chapter: ";

    int desiredChapter;

    while (true) {
        cin >> desiredChapter;

        if (!cin) {
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
        cin >> desiredChapter;

        if (!cin) {
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
        cin.clear();
        cin.ignore(1000, '\n'); 
        getline(cin, desiredContent); 

        if (cin.fail() || !cin) 
            cout << "Please try again: ";
        else
            break;
    }

    createRecord(taoTeChing, desiredChapter, desiredLine, desiredContent, true);

    cout << "The chapter is now as follows: " << endl;

    printChapter(desiredChapter, taoTeChing);
    
    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();

}

void updateLine(vector< vector<string> > &taoTeChing) { 
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter to update:  ";

    int desiredChapter;

    while (true) {
        cin >> desiredChapter;

        if (!cin) {
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

    cout << "Which line would you like to edit? ";
    int desiredLine;

    while (true) {
        cin >> desiredLine;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    cout << endl;

    cout << "What would you like the line to say? " << endl;

    string desiredContent;

    while (true) {
        getline(cin, desiredContent);

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    createRecord(taoTeChing, desiredChapter, desiredLine, desiredContent, true);

    cout << "The chapter is now as follows: " << endl;

    printChapter(desiredChapter, taoTeChing);

    cin.clear();
    cin.ignore(1000, '\n');
    waitForContinue();
}

void deleteLine(vector< vector<string> > &taoTeChing) {
    cout << "There are 81 Chapters in the Tao Te Ching. Input an integer to select the chapter from which to delete a line:  ";

    int desiredChapter;

    while (true) {
        cin >> desiredChapter;

        if (!cin) {
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

    cout << "Which line would you like to delete? ";
    int desiredLine;

    while (true) {
        cin >> desiredLine;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The input you provided is invalid. Please try again: ";
        } else {
            break;
        }
    }

    cout << endl;

    taoTeChing.erase(taoTeChing.begin() + desiredLine);

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

bool createRecord(vector< vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine, string &desiredContent, bool verbose) {
    size_t chapterActualSize = taoTeChing[desiredChapter].size();

    if (desiredLine >= chapterActualSize) { 
       taoTeChing[desiredChapter].push_back(desiredContent); 
       cout << endl;
    } else if (verbose) {
        cout << endl;
        cout << "Line to be replaced: ";
        readRecord(taoTeChing, desiredChapter, desiredLine); 
        taoTeChing[desiredChapter][desiredLine] = desiredContent; 
        cout << endl;
    }

    cout << "Line " << desiredLine << " now reads: ";
    readRecord(taoTeChing, desiredChapter, desiredLine); 

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

