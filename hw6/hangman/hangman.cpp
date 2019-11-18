#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::make_pair;
using std::for_each;
using std::getline;
using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::find;
using std::map;

void clearConsole();

void printCurrentProgress(map<char, bool> &quoteStatus);

bool printCurrentHangmanState(map<string, bool> &hangmanState);

bool promptUserInput(map<char, bool> &quoteStatus, map<string, bool> &hangmanState, bool &isFinished);

bool updateProgress(char &nextGuess, map<char, bool> &quoteStatus, bool &charFound);

bool promptUserInput(map<char, bool> &quoteStatus, map<string, bool> &hangmanState, bool &isFinished);

void updateHangmanState(map<string, bool> &hangmanState, bool &charFound);

int main() {

	bool isFinished = false;

	vector<string> hangmanItems {"head", "body", "right arm", "left arm", "right hand", "left hand", "right leg", "left leg", "right foot", "left foot"};

	map<string, bool> hangmanStatus;

	for_each(hangmanItems.begin(), hangmanItems.end(), [](string item, map<string, bool> &hangmanStatus) { 
			hangmanStatus.insert(make_pair(item, false));
	});

	string quote = "Whenever people tell me that I will regret whatever I just did when tomorrow morning comes, I sleep in until noon the next day, because I am a problem solver.";

	map<char, bool> quoteStatus;
	for_each(quote.begin(), quote.end(), [](char n, map<char, bool> &quoteStatus) {
		bool statusBool = false;
		if (n == '.' || n == ' ' || n == ',')
			statusBool = true;
		quoteStatus.insert(make_pair(n, statusBool)); 
	});

	while (!isFinished) {
		isFinished = promptUserInput(quoteStatus, hangmanStatus, isFinished); 
	}

	return 0; 
}

// Clear the console
void clearConsole() {

	cout << "\033[2J\033[1;1H";
}

bool printCurrentProgress(map<char, bool> &quoteStatus, bool &isFinished) { 
	isFinished = true;

	cout << "Current Progress:" << endl;

	string output;

	for_each(quoteStatus.begin(), quoteStatus.end(), [](pair<char, bool> n){
		if (n->second) {
			output = output + to_string(n->first); 
		} else {
			isFinished = false;
			output = output + "_";
		}
	});


	cout << output << endl << endl; 

	return isFinished;
}

bool printCurrentHangmanState(map<string, bool> &hangmanState, bool &isFinished, bool &charFound) {

	cout << "The hangedman's state of affairs: " << endl << endl;

	int turns = 0;

	for_each(hangmanState.begin(), hangmanState.end(), [](pair<string, bool> n) {
		if (n->second) {
			cout << setw(15) << left << n->first << endl;		
			turns++;
		}		
	});

	cout << "Turns: " << turns << "/10" << endl << endl;

	if (turns == 10)
		isFinished = true;

	return isFinished;
}

bool updateProgress(char &nextGuess, map<char, bool> &quoteStatus, bool &charFound) {
	for_each(quoteStatus.begin(), quoteStatus.end(), [](pair<char,bool> a) {
			if (a->first == nextGuess && a->second == false) {
				charFound = true;
				a->second = true;
			} 
	}); 

	return charFound;
}

void updateHangmanState(map<string, bool> &hangmanState, bool &charFound) {
	auto result1 = find(hangmanState.begin(), hangmanState.end(), false);
	if (result1 != hangmanState.end())
		result1->second = true;
}

bool promptUserInput(map<char, bool> &quoteStatus, map<string, bool> &hangmanState, bool &isFinished) {

	clearConsole();

	printCurrentProgress(quoteStatus, isFinished);

	if (isFinished) {
		cout << endl << "You win. Congrats!" << endl;
		return isFinished;
	} 

	printCurrentHangmanState(isFinished);

	if (isFinished) {
		cout << "You lose. Try again!" << endl;
		return isFinished;
	}

	cout << "Please provide your next guess as a single character: ";

	string temp;
	getline(cin, temp); 
	istringstream instream(temp);
	if (!instream)
		return isFinished;
	string temp_two << instream; 
	nextGuess = temp_two[0];
	
	bool charFound = false;
	charFound = updateProgress(nextGuess, quoteStatus);
	updateHangmanState(nextGuess, hangmanState, charFound);

	return isFinished; 
}
