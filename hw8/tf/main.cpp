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

    string filename = "***REMOVED***";
    // string filename = "the_wasteland_excerpt.txt";
    vector< pair<string, int> > vec;
    vector<string> stop_words;

    bool res;
   
    res = parseBook(filename, vec);
    if (!res)
        return 0;

    res = sortBook(vec); 
    if (!res)
        return 0;

    res = loadStopWords(stop_words);
    if (!res)
        return 0;

    res = filterRes(vec, stop_words);
    if (!res)
        return 0;

    res = printRes(vec);

	return 0;
}

bool parseBook(string& filename, vector< pair<string, int> >& vec) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cout << "Error parsing book" << endl;
        return false;
    }

    string s1;
	while (file >> s1) {

        // this should instead remove any of the ",. etc. characters across the
        // whole string, and then continue
        if (s1.back() == '.' || s1.back() == ',') {
            s1 = s1.substr(0, s1.length() - 1);
        }

        std::for_each(s1.begin(), s1.end(), [](char& c) {
            c = std::tolower(c);
        }); 

        if (s1.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos) {
            continue;
        }
        
        auto it = find_if( vec.begin(), vec.end(), [&s1](const pair<string, int>& element) {
           return element.first == s1; 
        });

        if ( it == vec.end() ) {
            vec.push_back(make_pair(s1, 0));
        } else {
            it->second++;
            //(vec.begin() + it).second = val + 1;
            // (*it).second == val + 1;
        } 
	}
    return true;
}

bool sortBook(vector< pair<string, int> >& vec) {
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
                return (a.second > b.second);
    });
    return true;
}

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

bool filterRes(vector< pair<string, int> >& vec, vector<string>& stop_words) {
    for (size_t i = 0; i < stop_words.size(); i++) {
        string currStop = stop_words[i];
        auto it = find_if(vec.begin(), vec.end(), [&currStop](const pair<string, int>& element) {
                return element.first == currStop;
        });
        if ( it != vec.end() ) {
            it = vec.erase(it);
        }
    }
    return true;
}

bool printRes(vector< pair<string, int> >& vec) {
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

