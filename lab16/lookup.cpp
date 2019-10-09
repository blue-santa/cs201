// lookup.cpp  INCOMPLETE
// Glenn G. Chappell
// 23 Feb 2018
//
// For CS 201 Spring 2018
// Look-up by Key

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::getline;
using std::istringstream; 

// sequentialSearch
// Given a vector<int> holding keys, and a vector<string> holding the
// associated values, and a key to search for (thekey). Does Sequential
// Search in an attempt to find the given key. If it is not found,
// returns false. If it is found, sets thevalue to the associated value
// and returns true.

bool sequentialSearch(vector<int> keys,
                  vector<string> values,
                  int thekey,
                  string & thevalue) { 
    for (size_t i {0}; i < keys.size(); i++) {
        if (keys.at(i) == thekey) { 
            thevalue = values.at(i);
            return true;
        }
    } 

    return false;
}

bool addDataset(vector<int> & keys,
                vector<string> & values,
                int thekey,
                string & newString) { 

        cout << "Please provide a string value to place in the dataset: ";

        while (true) {

            // string tempString;
            getline(cin, newString);

            if (!cin)
                return false;
            if (newString == "")
                return false;

            // istringstream in(tempString);
            // in >> newString;
            // if (!in)
            // {
                // cout << "Please try again" << endl;
                // cout << endl;
                // continue;
            // }

            keys.push_back(thekey);
            values.push_back(newString);
            break;
        }
        return true;
}

// Main program
// Create a dataset, and do searches in it.

int main()
{
    // Make associative (KEY-VALUE) dataset
    vector<int> keys {
        21,
        22,
        23,
        25,
        27,
        31,
        32,
        33,
        36,
        38
    };
    vector<string> values {
        "Alice Smith",
        "Bill Jones",
        "Charles Johnson",
        "Daphne Robertson",
        "Egbert Williams",
        "Fifi Phillips",
        "George Watson",
        "Harriet Baker",
        "Iris Gump",
        "Jake Hawkins"
    };

    // Print opening message
    cout << "Sequential Search in an associative dataset" << endl;
    cout << endl;

    // Input & search loop
    while (true)
    {
        // Get a line
        cout << "Type a positive integer KEY (empty line to end): ";
        string line;
        getline(cin, line);
        if (!cin)
            return 0;
        if (line == "")
            break;

        // Get an int from the above line
        istringstream in(line);
        int thekey;
        in >> thekey;
        if (!in)
        {
            cout << "Please type a positive integer" << endl;
            cout << endl;
            continue;
        }
        if (thekey < 1)
        {
            cout << "Please type a positive integer" << endl;
            cout << endl;
            continue;
        }

        string thevalue;
        bool found = sequentialSearch(keys, values, thekey, thevalue);
        if (found)
        {
            cout << "KEY found; VALUE = " << thevalue << endl;
        }
        else
        {
            cout << "KEY not found" << endl;

            string newString;
            addDataset(keys, values, thekey, newString);
            continue;
        }
        cout << endl;
    }
    cout << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}

