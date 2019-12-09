/*
 * main.cpp
 * CS 201
 * December 8, 2019
 * Bryan Beus
 * The main file for the tf project of hw8
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <iterator>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::setw;
using std::make_pair;
using std::ifstream;
using std::sort;
using std::left;
using std::right;
using std::find_if;

bool readFile(string& filename, ifstream& ifs); 
bool parseBook(string& filename, vector< pair<string, int> >& vec); 
bool parseWordList(string& filename, vector<string >& word_list);
bool sortBook(vector< pair<string, int> >& vec); 
bool loadStopWords(vector<string>& stop_words); 
bool filterRes(vector< pair<string, int> >& vec, vector<string>& stop_words); 
bool printRes(vector< pair<string, int> >& vec);

int main() {

    // Set initial filename
    string filename = "***REMOVED***";

    // Create initial vectors for holding data
    vector< pair<string, int> > vec;
    vector<string> stop_words;

    // Create res for software kill switch, if anything fails
    bool res;
   
    // Import and parse the chosen book
    res = parseBook(filename, vec);
    if (!res)
        return 0;

    // Sort the book's values
    res = sortBook(vec); 
    if (!res)
        return 0;

    // Load the stop words
    res = loadStopWords(stop_words);
    if (!res)
        return 0;

    // Filter the book based on the stop words
    res = filterRes(vec, stop_words);
    if (!res)
        return 0;

    // Print the result
    res = printRes(vec);

	return 0;
}

// Parse the book into a vector that holds each word and its count
bool parseBook(string& filename, vector< pair<string, int> >& vec) {

    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cout << "Error parsing book" << endl;
        return false;
    }

    string s1;
	while (file >> s1) {

        // To keep words that end with a period or comma, truncate these word's
        // strings
        if (s1.back() == '.' || s1.back() == ',') {
            s1 = s1.substr(0, s1.length() - 1);
        }

        // Make all letters lowercase
        std::for_each(s1.begin(), s1.end(), [](char& c) {
            c = std::tolower(c);
        }); 

        // Ensure that we have a regular word, and not a special character
        // value
        if (s1.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos) {
            continue;
        }
        
        // Search the vec vector to see if this s1 word has already occured
        auto it = find_if( vec.begin(), vec.end(), [&s1](const pair<string, int>& element) {
           return element.first == s1; 
        });

        // If it has not occurred, add it to the vector and set the initial
        // value
        if ( it == vec.end() ) {
            vec.push_back(make_pair(s1, 1));

        // Otherwise, increase the iteration->second value for the discovered
        // vector/pair value
        } else {
            it->second++;
        } 
	}
    return true;
}

// Sort the book with highest occuring values towards the front
bool sortBook(vector< pair<string, int> >& vec) {
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
                return (a.second > b.second);
    });
    return true;
}

// Load the list of stop words to avoid
bool loadStopWords(vector<string>& stop_words) { 
    string filename = "stop_word_list.txt";
    ifstream file(filename);

    if (!file) {
        return false;
    }

    string s1; 
    while (file >> s1) { 
        stop_words.push_back(s1); 
    }

    return true; 
}

// Filter the resulting vec vector by the stop_words vector
bool filterRes(vector< pair<string, int> >& vec, vector<string>& stop_words) {

    for (size_t i = 0; i < stop_words.size(); i++) {
        string currStop = stop_words[i];
        auto it = find_if(vec.begin(), vec.end(), [&currStop](const pair<string, int>& element) {
                return element.first == currStop;
        });

        // If a matching stop_words word is found in the vector, erase it
        if ( it != vec.end() ) {
            it = vec.erase(it);
        }
    }
    return true;
}

// Print the result to the screen
bool printRes(vector< pair<string, int> >& vec) {

    // Test that the vector is longer than 20, to ensure no undefined behavior
    // below
    if (vec.size() < 21) {
        cout << "Vector is not valid" << endl;
        return false;
    }

    for (int i = 0; i < 20; i++) {
        auto it = vec.begin() + i;
        cout << setw(2) << right << i + 1 <<  ":  ";
        cout << setw(35) << left << it->first;  
        cout << setw(10) << left << "occurances:  ";
        cout << setw(15) << left << it->second << endl;
    }

    return true;
}

