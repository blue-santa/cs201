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

// Clear the console

void clearConsole();

// Wait for user input

void waitForContinue();

// Display the main prompt screen

bool displayPrompt(vector<string> & names, vector<int> & scores);

// Request the user to input a name and score

bool addInput(vector<string> & names, vector<int> & scores);

// Request a name

bool requestName(vector<string> & names, string & newName);

// Request a score

bool requestScore(vector<int> & scores, int & newScore, string & newName);

// Check that the inputted name is not a duplicate

bool checkOriginal(string & newName, vector<string> & names);

// Check that the lengths of the vectors match

bool checkLengths(vector<string> & names, vector<int> & scores);

// Check that the database is not empty

bool checkDatabaseHasInputs(vector<string> & names);

// Print a list of names and scores

bool printList(vector<string> & names, vector<int> & scores, bool wait);

// Search for a name in the database

void searchName(vector<string> & names, vector<int> & scores);

// Search for a score in the database

void searchScore(vector<string> & names, vector<int> & scores); 

int main(int argc, char **argv) {

    // Declare names and scores vectors

	vector<string> names;
	vector<int> scores;

    // Initiate endless while loop to maintain program stream

	while (true) {

        // Initiate bool variable to allow program to end, if needed
        // Call main displayPrompt() function to beging program

		bool result = displayPrompt(names, scores); 

        // If result is ever returned negative, end the program

		if (!result) {
			break;
		}
	}

	return 0;
}

// Clear the console

void clearConsole() { 
	cout << "\033[2J\033[1;1H"; 
}

// Wait for user input

void waitForContinue() { 
	cout << "Press enter to continue . . . ";
	getchar();

    // Clear cin

    cin.clear();
    cin.ignore(1000, '\n');
}

// Display the main prompt screen

bool displayPrompt(vector<string> & names, vector<int> & scores) {

    // Clear the console

	clearConsole();

    // Declare a result variable that will be sent back to the int main() function's while loop

	bool result = true;

    // Declare option variable to capture user input for program direction

    int option;
   
    // Display options 

	cout << "Choose an option from the following menu: " << endl;
	cout << "\n1) Add new names and scores to the database" << endl;
	cout << "2) Print the full list of names and scores" << endl;
	cout << "3) Search for a name" << endl;
	cout << "4) Search for a score" << endl;
	cout << "0) End program\n" << endl; 

    // Initiate endless while loop
    // Loop continues until user provides valid input

    while (true) {
        
        // Capture input

        cin >> option;

        // Ensure input is valid 

        if (cin.fail() || option > 4 || option < 0) {

            // Clear cin

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nThe option you selected is not valid. Please try again: ";

            // If the input is valid, then break the loop to continue

        } else {
            break;
        }
    }

    // Initiate switch method to determine response to input

	switch (option) {

        // Add an input

		case 1: 
			result = addInput(names, scores);
			break;

        // Print a list of names

		case 2:
			printList(names, scores, true);
			break;

        // Search for a name in the database

		case 3:
			searchName(names, scores);
			break;

        // Search for a score in the database

		case 4:
			searchScore(names, scores);
			break;

        // End the program by returning false

		case 0:
			result = false;
			break;

        // Restart stream by default

		default:
			break; 
	}

    // Return the result to the endless while loop in int main() 

	return result;
}

// Request the user to input a name and score

bool addInput(vector<string> & names, vector<int> & scores) {

    // Declare result variable to monitor user progress, and if necessary, return a false value, and thus end the program
     
    bool result = true;

    // Clear the console

	clearConsole();

    // Print request for user input 

	cout << "Please enter names and scores for the database." << endl;
	cout << "\nTo indicate that you are finished entering data, input a name as \"NoName\" paired with a score of \"0\"\n" << endl;

    // Initiate endless while loop to request new name

	while (true) {

        // Declare newName variable
        // Declare newScore variable

        string newName; 
        int newScore;

        // Declare result variable to ensure call to requestName() function is succesfull
        // Call requestName() function

        result = requestName(names, newName);

        // If the result is unsuccessful, end the loop (and program)

        if (!result) {
            break;

            // Otherwise, call the requestScore() function and set the response to the result variable

        } else if (result) {
            result = requestScore(scores, newScore, newName);
        }

        // Check to see if the input values are NoName and 0
        // If so, end the while loop

        if (newName == "NoName" && newScore == 0) {
            break;
        }
	} 

    // Check that the length of the names and scores vectors are the same
    // If not, end the program with error message

    if (!checkLengths(names, scores)) {
        cout << "The names and scores vectors are of different lengths. Something is wrong in the code." << endl;
        result = false;
    }

    // Return the result

    return result;
}

// Request a name for the names vector

bool requestName(vector<string> & names, string & newName) {

    // Declare the result variable to return at the end

    bool result = true;

    // Print request for new name

    cout << "Enter a new name for the database: "; 

    // Initiate endless while loop to request new name

    while (true) {

        // Capture new name

        cin >> newName; 

        // If the input type is invalid, start again

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "\nThe input you provided is not valid. Please try again.\n" << endl; 

            // Check that this input name is original
            // If it is not, end the program

        } else if (!checkOriginal(newName, names)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nThe name you provided is already in the database. Terminating program (as per instructions)." << endl;
            result = false;
            break;

            // Check to see if the user is beginning the termination process

        } else if (newName == "NoName") {
            break;

            // Add the name to the database
        } else { 
            names.push_back(newName);
            break;
        }
    } 
    
    // Return the result

    return result;
}

// Request a new score

bool requestScore(vector<int> & scores, int & newScore, string & newName) {

    // Declare result variable to monitor function progress

    bool result = true;

    // Check to see if the current newName variable is NoName
    // If it is, request user to confirm by entering 0
    if (newName == "NoName") {


        cout << "\nPlease confirm by entering '0' as a score.\n" << endl;

        // Initiate endless while loop to capture valid user response

        while (true) {

            // Capture user input

            cin >> newScore;
            
            // Verify user input

            if (cin.fail()) { 
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input provided is not a valid integer. Please try again." << endl; 

                // If the user input is 0, return to the main display prompt 

            } else if (newScore == 0) {
                return result;

                // If the user enters a valid input other that 0, continue putting new names and scores into the database

            } else {
                cout << "\nContinuing with name and score database inputs.\n" << endl;
                break;
            }
        }

    // If the newName variable is not 'NoName,' begin the process for collecting a matching score

    } else {

        // Request new score

        cout << "Enter the score for " << newName << ": "; 

        // Initiate endless while loop to capture valid user score

        while (true) {

            // Capture new score value

            cin >> newScore;

            // If input is invalid restart the loop

            if (cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input provided is not valid. Please try again: ";

            // Otherwise, add the new score to the database and end the loop

            } else {

                scores.push_back(newScore); 
                break;

            }
        }
    }

    // Return the result variable

    return result;

}

// Check that the input newName variable is not a duplciate

bool checkOriginal(string & newName, vector<string> & names) {

    // Declare isOriginal variable to check whether newName is new

    bool isOriginal = true;

    // Iterate through names vector to check for duplicates

    for (int i = 0; i < names.size(); i++) {

        // If a duplicate is found, set isOriginal to false
        if (names.at(i) == newName) {
            isOriginal = false;
        }
    }

    // Return result

    return isOriginal;
}

// Check to make sure that names and scores vectors are valid

bool checkLengths(vector<string> & names, vector<int> & scores) {

    // Check that the lengths are correct, and return a bool result

    bool isCorrect = (names.size() == scores.size()) ? true : false; 

    // Return the bool result

    return isCorrect;

}

// Check that the database of names is not empty 

bool checkDatabaseHasInputs(vector<string> & names) {

    // If size of names vector is less than one, return instructions to user, wait for user to confirm, and then end the function with a negative

    if (names.size() < 1) { 
        cout << "You must put names and scores in the database before attempting to read it." << endl;
        waitForContinue();
        return false;
    }

    // If the size is greater than or equal to one, return positive

    return true;

}

// Print a list of provided names and scores

bool printList(vector<string> & names, vector<int> & scores, bool wait) {

    // Clear the console

    clearConsole();

    // Check that the database is not empty

    if (checkDatabaseHasInputs(names)) { 

        // Print the names and scores in columns

        while (true) {

            // Declare names and scores title strings

            string columnOne = "Names";
            string columnTwo = "Scores";

            // Declare variable for standard char size of column one

            int columnSize = columnOne.length() + 3;

            // Iterate through list of names and discover longest column one name

            for (int i = 0; i < names.size(); i++) {
                if (names.at(i).length() > columnSize + 3) {
                    columnSize = names.at(i).length() + 3;
                }
            }

            // Declare variables to manage column formatting

            int columnTitleSpaces = columnSize - columnOne.length(); 
            int dashCount = columnTwo.length() + columnSize;

            // Print column titles

            cout << columnOne << string(std::max(columnTitleSpaces, 3), ' ') << columnTwo << endl;
            cout << string(dashCount, '-') << endl;

            // Print all names and scores

            for (int i = 0; i < names.size(); i++) {
                cout << names.at(i) << string(columnSize - names.at(i).length(), ' ') << scores.at(i) << endl;
            }

            // Wait for user to continue

            if (wait) {
                waitForContinue();
            }

            // End while loop 

            break;

        } 
    }
}

// Search for a name in the database

void searchName(vector<string> & names, vector<int> & scores) {

    // Clear the console

    clearConsole();

    // Declare searchName variable
    //  Initiate nameFound variable and begin with default at negative

    string searchName;
    bool nameFound = false;

    // Declare a tempName and tempScore varaible 
    // If name(s) and score(s) are found, these variable are sent to the printList() function

    vector<string> tempName;
    vector<int> tempScore;

    // Verify that the database is not empty

    if (checkDatabaseHasInputs(names)) {

    // Print request for user input

    cout << "Enter the name for which to search the database: ";

    // Initiate endless while loop to request valid user input

        while (true) {

            // Capture user input

            cin >> searchName;

            // If input is invalid, restart loop

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input you provided is not valid. Please try again: ";
             
            // Iterate through the list of names and search for matching names

            } else {
                for (int i = 0; i < names.size(); i++) {
                    if (names.at(i) == searchName && !nameFound) {

                        // If name is found, set nameFound to true

                        nameFound = true;

                        // Set tempName and tempScore values and send call to printList() function

                        tempName.push_back(names.at(i));
                        tempScore.push_back(scores.at(i)); 
                        printList(tempName, tempScore, true);

                    } 
                }

                // If no matching name is found, inform the user

                if (!nameFound) {
                    cout << "\nName not found." << endl;
                    waitForContinue();
                }

                // End loop

                break;
            }
        }
    }
}

// Search database for a score

void searchScore(vector<string> & names, vector<int> & scores) {

    // Clear the console

    clearConsole();

    // Declare searchScore and scoreFound variables

    int searchScore;
    bool scoreFound = false;

    // Declare tempName and tempScore variables to hold potential name(s) and score(s)

    vector<string> tempName;
    vector<int> tempScore;

    // Check that the database is not empty

    if (checkDatabaseHasInputs(names)) {
        
        // Request user input

        cout << "Enter the score for which to search the database: ";

        // Initiate endless while loop to request valid user input

        while (true) {

            // Capture user input

            cin >> searchScore;

            // If input is invalid, restart loop

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The input you provided is not valid. Please try again: ";

            // Iterate through the list of scores and capture all matching values
            // For each matching value, push to the tempName and tempScore vectors

            } else {
                for (int i = 0; i < scores.size(); i++) {
                    if (scores.at(i) == searchScore) {
                        scoreFound = true;
                        tempName.push_back(names.at(i));
                        tempScore.push_back(scores.at(i)); 
                        
                        // Send all matching names and scores to printList() function for printing

                        printList(tempName, tempScore, false);
                    }
                }

                // If no matching score is found, inform the user

                if (!scoreFound) {
                    cout << "\nScore not found." << endl;
                }

                // Wait for user to indicate readiness

                waitForContinue(); 

                // End loop

                break;
            } 
        }
    }
}

