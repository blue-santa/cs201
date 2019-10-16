/**
 * database.hpp
 * CS 201
 * Bryan Beus
 * October 14, 2019
 * Header file
 */

#ifndef _DATABASE_HPP_
#define _DATABASE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>
#include <chrono>
#include <thread>

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

// Print a selected chapter
void selectChapter(vector< vector<string> > &taoTeChing);

// Add a line to a chapter
void addLine(vector< vector<string> > &taoTeChing);

// Update an existing line in a chapter
void updateLine(vector< vector<string> > &taoTeChing);

// Delete a line from a chapter
void deleteLine(vector< vector<string> > &taoTeChing);

// Wait for user response
void waitForContinue();

// Clear the console
void clearConsole();

// Create a new record
bool createRecord(vector< vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine, string &desiredContent);

// Read an existing record
bool readRecord(vector < vector<string> > &taoTeChing, int &desiredChapter, int &desiredLine);

// Print a full chapter to the console
void printChapter(int &desiredChapter, const vector< vector<string> > taoTeChing);

// Load the initial database
bool loadDatabase(vector< vector<string> > &taoTeChing);

// Display the main menu
int displayOptions(int & option);

#endif
