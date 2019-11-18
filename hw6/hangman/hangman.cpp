#include <cstdlib>
#include <iostream>
#include <iomanip>
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
using std::cin;
using std::endl;
using std::make_pair;
using std::for_each;
using std::getline;
using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::find;
using std::map;
using std::setw;
using std::left;

void clearConsole();

void printCurrentProgress(map<char, bool> &quoteStatus);

bool printCurrentHangmanState(map<bool, string> &hangmanState, bool &isFinished);

bool promptUserInput(map<char, bool> &quoteStatus, map<bool, string> &hangmanState, bool &isFinished);

bool updateProgress(char &nextGuess, map<char, bool> &quoteStatus, bool &charFound);

bool promptUserInput(map<char, bool> &quoteStatus, map<bool, string> &hangmanState, bool &isFinished);

void updateHangmanState(map<bool, string> &hangmanState, bool &charFound);

int main() {

	bool isFinished = false;

	vector<string> hangmanItems {"head", "body", "right arm", "left arm", "right hand", "left hand", "right leg", "left leg", "right foot", "left foot"};

	map<bool, string> hangmanState;

	for_each(hangmanItems.begin(), hangmanItems.end(), [&hangmanState](string item) { 
			hangmanState.insert(make_pair(false, item));
	});

	string quote = "Whenever people tell me that I will regret whatever I just did when tomorrow morning comes, I sleep in until noon the next day, because I am a problem solver.";

	map<char, bool> quoteStatus;
	for_each(quote.begin(), quote.end(), [&quoteStatus](char n) {
		bool statusBool = false;
		if (n == '.' || n == ' ' || n == ',')
			statusBool = true;
		quoteStatus.insert(make_pair(n, statusBool)); 
	});

	while (!isFinished) {
		isFinished = promptUserInput(quoteStatus, hangmanState, isFinished); 
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

	for_each(quoteStatus.begin(), quoteStatus.end(), [&output, &isFinished](auto &n){
		if (n.second) {
			output = output + to_string(n.first); 
		} else {
			isFinished = false;
			output = output + "_";
		}
	});


	cout << output << endl << endl; 

	return isFinished;
}

bool printCurrentHangmanState(map<bool, string> &hangmanState, bool &isFinished) {

	cout << "The hangedman's state of affairs: " << endl << endl;

	int turns = 0;

	for_each(hangmanState.begin(), hangmanState.end(), [&turns](auto &n) {
		if (n.first) {
			cout << setw(15) << left << n.second << endl;
			turns++;
		}		
	});

	cout << "Turns: " << turns << "/10" << endl << endl;

	if (turns == 10)
		isFinished = true;

	return isFinished;
}

bool updateProgress(char &nextGuess, map<char, bool> &quoteStatus, bool &charFound) {
	for_each(quoteStatus.begin(), quoteStatus.end(), [&nextGuess, &charFound](auto &n) {
			if (n.first == nextGuess && n.second == false) {
				charFound = true;
				n.second = true;
			} 
	}); 

	return charFound;
}

void updateHangmanState(map<bool, string> &hangmanState, bool &charFound) {
	map<bool, string>::iterator res = hangmanState.find(false);
	if (res != hangmanState.end())
		res->first = true;
}

bool promptUserInput(map<char, bool> &quoteStatus, map<bool, string> &hangmanState, bool &isFinished) {

	clearConsole();

	printCurrentProgress(quoteStatus, isFinished);

	if (isFinished) {
		cout << endl << "You win. Congrats!" << endl;
		return isFinished;
	} 

	printCurrentHangmanState(hangmanState, isFinished);

	if (isFinished) {
		cout << "You lose. Try again!" << endl;
		return isFinished;
	}

	cout << "Please provide your next guess as a single character: ";

	string temp;
	string temp_two;
	char nextGuess;

	getline(cin, temp); 
	istringstream instream(temp);
	if (!instream)
		return isFinished;
	instream >> temp_two; 
	nextGuess = temp_two[0];
	
	bool charFound = false;
	charFound = updateProgress(nextGuess, quoteStatus, charFound);
	updateHangmanState(hangmanState, charFound);

	return isFinished; 
}
