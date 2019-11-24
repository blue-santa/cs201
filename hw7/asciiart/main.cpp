#include <iostream>
#include <vector>
#include <fstream>

#include "Color3.hpp" 
#include "Image3.hpp"

using std::cout;
using std::cin;
using std::endl;

using std::ofstream;

int main() {

	Color3 myColor(10, 85, 127);

	ofstream fout ("testfile.txt");
	if (!fout) {
		cout << "error opening file" << endl;
		// something here to close the file or stop it from being used
	}

	fout << myColor;

	return 0;


}
