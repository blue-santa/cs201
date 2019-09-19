/**
 * scores.cpp
 * CS 201
 * Bryan Beus
 * September 18, 2019
 * A program to record names and scores in two separate vectors
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;

void clearConsole();

void waitForContinue();

bool displayPrompt(vector<string> & names, vector<int> & scores);

bool addInput(vector<string> & names, vector<int> & scores);

bool requestName(vector<string> & names, string & newName);

bool requestScore(vector<int> & scores, int & newScore, string & newName);

bool checkOriginal(string & newName, vector<string> & names);

bool checkLengths(vector<string> & names, vector<int> & scores);

bool checkDatabaseHasInputs(vector<string> & names);

bool printList(vector<string> & names, vector<int> & scores, bool wait);

void searchName(vector<string> & names, vector<int> & scores);

void searchScore(vector<string> & names, vector<int> & scores); 

int main(int argc, char **argv) {

	vector<string> names;
	vector<int> scores;

	while (true) {
		bool result = displayPrompt(names, scores); 

		if (!result) {
			break;
		}
	}

	return 0;
}

void clearConsole() { 
	cout << "\033[2J\033[1;1H"; 
}

void waitForContinue() { 
	cout << "Press enter to continue . . . ";
	getchar();
    cin.clear();
    cin.ignore(1000, '\n');
}

bool displayPrompt(vector<string> & names, vector<int> & scores) {

	clearConsole();

	bool result = true;
    int option;
   
	cout << "Choose an option from the following menu: " << endl;
	cout << "\n1) Add new names and scores to the database" << endl;
	cout << "2) Print the full list of names and scores" << endl;
	cout << "3) Search for a name" << endl;
	cout << "4) Search for a score" << endl;
	cout << "0) End program\n" << endl; 

    while (true) {
        cin >> option;

        if (cin.fail() || option > 4 || option < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nThe option you selected is not valid. Please try again: ";
        } else {
            break;
        }
    }

	switch (option) {

		case 1: 
			result = addInput(names, scores);
			break;
		case 2:
			printList(names, scores, true);
			break;
		case 3:
			searchName(names, scores);
			break;
		case 4:
			searchScore(names, scores);
			break;
		case 0:
			result = false;
			break;
		default:
			break; 
	}


	return result;
}

bool addInput(vector<string> & names, vector<int> & scores) {
     
    bool result = true;

	clearConsole();

	cout << "Please enter names and scores for the database." << endl;
	cout << "\nTo indicate that you are finished entering data, input a name as \"NoName\" paired with a score of \"0\"\n" << endl;

	while (true) {

        string newName; 
        int newScore;

        result = requestName(names, newName);

        if (!result) {
            break;
        } else if (result) {
            result = requestScore(scores, newScore, newName);
        }

        if (newName == "NoName" && newScore == 0) {
            break;
        }
	} 

    if (!checkLengths(names, scores)) {
        cout << "The names and scores vectors are of different lengths. Something is wrong in the code." << endl;
        result = false;
    }

    return result;
}

bool requestName(vector<string> & names, string & newName) {

    bool result = true;

    cout << "Enter a new name for the database: "; 

    while (true) {

        cin >> newName; 

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "\nThe input you provided is not valid. Please try again.\n" << endl; 
        } else if (!checkOriginal(newName, names)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nThe name you provided is already in the database. Terminating program (as per instructions)." << endl;
            result = false;
            break;
        } else if (newName == "NoName") {
            break;
        } else {
            // cout << "Pushing " << newName << " to the database.\n" << endl; 
            names.push_back(newName);
            break;
        }
    } 

    return result;
}

bool requestScore(vector<int> & scores, int & newScore, string & newName) {

    bool result = true;

    if (newName == "NoName") {

        cout << "\nPlease confirm by entering '0' as a score.\n" << endl;

        while (true) {

            cin >> newScore;
            
            if (cin.fail()) { 
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input provided is not a valid integer. Please try again." << endl; 
            } else if (newScore == 0) {
                return result;
            } else {
                cout << "\nContinuing with name and score database inputs.\n" << endl;
                break;
            }
        }

    } else {

        cout << "Enter the score for " << newName << ": "; 

        while (true) {

            cin >> newScore;

            if (cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input provided is not valid. Please try again: ";

            } else {

                // cout << "\nPushing " << newScore << " to the database as a score for " << newName << endl << endl; 
                scores.push_back(newScore); 
                break;

            }
        }
    }

    return result;

}

bool checkOriginal(string & newName, vector<string> & names) {

    bool isOriginal = true;

    for (int i = 0; i < names.size(); i++) {
        if (names.at(i) == newName) {
            isOriginal = false;
        }
    }

    return isOriginal;
}

bool checkLengths(vector<string> & names, vector<int> & scores) {

    bool isCorrect = (names.size() == scores.size()) ? true : false; 
    return isCorrect;

}

bool checkDatabaseHasInputs(vector<string> & names) {

    if (names.size() < 1) { 
        cout << "You must put names and scores in the database before attempting to read it." << endl;
        waitForContinue();
        return false;
    }

    return true;

}

bool printList(vector<string> & names, vector<int> & scores, bool wait) {

    clearConsole();

    if (checkDatabaseHasInputs(names)) { 

        while (true) {

            string columnOne = "Names";
            string columnTwo = "Scores";

            int columnSize = columnOne.length() + 3;

            for (int i = 0; i < names.size(); i++) {
                if (names.at(i).length() > columnSize + 3) {
                    columnSize = names.at(i).length() + 3;
                }
            }

            int columnTitleSpaces = columnSize - columnOne.length(); 
            int dashCount = columnTwo.length() + columnSize;

            cout << columnOne << string(std::max(columnTitleSpaces, 3), ' ') << columnTwo << endl;
            cout << string(dashCount, '-') << endl;

            for (int i = 0; i < names.size(); i++) {
                cout << names.at(i) << string(columnSize - names.at(i).length(), ' ') << scores.at(i) << endl;
            }

            if (wait) {
                waitForContinue();
            }

            break;

        } 
    }
}

void searchName(vector<string> & names, vector<int> & scores) {

    clearConsole();

    string searchName;
    bool nameFound = false;
    vector<string> tempName;
    vector<int> tempScore;

    if (checkDatabaseHasInputs(names)) {

    cout << "Enter the name for which to search the database: ";

        while (true) {

            cin >> searchName;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input you provided is not valid. Please try again: ";
            } else {
                for (int i = 0; i < names.size(); i++) {
                    if (names.at(i) == searchName && !nameFound) {

                        nameFound = true;

                        tempName.push_back(names.at(i));
                        tempScore.push_back(scores.at(i)); 
                        printList(tempName, tempScore, true);

                    } 
                }

                if (!nameFound) {
                    cout << "\nName not found." << endl;
                    waitForContinue();
                }

                break;
            }
        }
    }
}

void searchScore(vector<string> & names, vector<int> & scores) {

    clearConsole();

    int searchScore;
    bool scoreFound = false;
    vector<string> tempName;
    vector<int> tempScore;


    if (checkDatabaseHasInputs(names)) {
        
        cout << "Enter the score for which to search the database: ";

        while (true) {

            cin >> searchScore;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input you provided is not valid. Please try again: ";
            } else {
                for (int i = 0; i < scores.size(); i++) {
                    if (scores.at(i) == searchScore) {
                        scoreFound = true;
                        tempName.push_back(names.at(i));
                        tempScore.push_back(scores.at(i)); 
                        printList(tempName, tempScore, false);
                    }
                }

                if (!scoreFound) {
                    cout << "\nScore not found." << endl;
                }

                waitForContinue(); 

                break;
            } 
        }
    }
}

