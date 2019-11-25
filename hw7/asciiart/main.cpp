#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Color3.hpp" 
#include "Image3.hpp"

using std::cout;
using std::cin;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::vector;
using std::string;

int main() {

	// Load file
	string input_path = "parrot.ppm";
	string output_path = "test.ppm";
	string ascii_output_path = "ascii.txt";
	string file_contents;

	Image3 image(0, 0); 

	ifstream fin2(input_path);

	if (!fin2)
		cout << "no fin" << endl;

	fin2 >> image;

	fin2.close();

	ofstream fout2(output_path);

	if (!fout2)
		cout << "no fout" << endl;

	fout2 << image;

	fout2.close();

	ofstream fout3(ascii_output_path);

	if (!fout3)
		cout << "no fout3" << endl;


	image.printASCII(fout3);


	
	/*

	loaded = image.loadPPM(input_path, file_contents);

	if (!loaded) { 
		cout << "Error loading image" << endl;
	} 

	ofstream fout(output_path);

	if (!fout) {
		cout << "Failed to create output file" << endl; 
		return 0;
	}

	image.printASCII(fout); 
	*/

	return 0; 
}
