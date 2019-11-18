#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::map;
using std::make_pair;
using std::for_each;
using std::getline;
using std::istringstream;
using std::ostringstream;

using SizeStringPair = std::pair<size_t, std::string>;

void clearConsole();

void printCurrentProgress(map<char, bool> &quoteStatus);

bool printCurrentHangmanState(map<string, bool> &hangmanState);

void promptUserInput(map<char, bool> &quoteStatus, bool &isFinished);

int main() {

	bool isFinished = false;

	vector<string> hangmanItems {"head", "body", "right arm", "left arm", "right hand", "left hand", "right leg", "left leg", "right foot", "left foot"};

	map<string, bool> hangmanStatus;


	string quote = "Whenever people tell me that I will regret whatever I just did when tomorrow morning comes, I sleep in until noon the next day, because I am a problem solver.";

	map<char, bool> quoteStatus;
	for_each(quote.begin(), quote.end(), [](char n) {
		bool statusBool = false;
		if (n == '.' || n == ' ' || n == ',')
			statusBool = true;
		map.insert(make_pair(n, statsBool)); 
	});

	while (!isFinished) {
		isFinished = promptUserInput(quoteStatus, isDead, userWon); 
	}

	return 0;


	cout << endl << "Part 3: " << endl;

	vector<SizeStringPair>::iterator it = std::find_if(v.begin(), v.end(), [](SizeStringPair a) {
		return a.first > 15;
	});

	while (it->first > 15) { 
		std::cout << "{ "<< it->first << ", "<< it->second << " }" << std::endl; 
		it++;
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

	std::ostringstream output;

	for_each(quoteStatus.begin(), quoteStatus.end(), [](map<char, bool>::iterator n){
		if (n->second) {
			output << n->first; 
		} else {
			isFinished = false;
			output << '_';
		}
	});

	cout << output << endl << endl; 

	return isFinished;
}

bool printCurrentHangmanState(map<string, bool> &hangmanState, bool &isFinished) {

	return isFinished;
}

bool promptUserInput(map<char, bool> &quoteStatus, bool isFinished) {

	clearConsole();
	printCurrentProgress(quoteStatus, isFinished);

	if (isFinished) {
		cout << endl << "You win. Congrats!" << endl;
		return isFinished
	} 

	printCurrentHangmanState(isFinished);

	if (isFinished) {
		cout << "You lose. Try again!" << endl;
		return isFinished
	}

	cout << "Please provide your next guess as a single character: ";

	string temp;
	getline(cin, temp); 
	istringstream instream(temp);
	if (!instream)
		return isFinished;
	string temp_two << instream; 
	nextGuess = temp_two[0];
	
	updateProgress(nextGuess, quoteStatus);
	updateHangmanState(nextGuess, hangmanState);

}
