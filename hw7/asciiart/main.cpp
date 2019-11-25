/*
 * main.cpp
 * Bryan Beus
 * November 24, 2019
 * The main file for the ascii art project
 */

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

	// Declare file paths
	string input_path = "parrot.ppm";
	string output_path = "test.ppm";
	string ascii_output_path = "ascii.txt";

	// Create empty image object for manipulation
	Image3 image(0, 0); 

	// Create input stream from input path
	ifstream fin2(input_path);

	if (!fin2)
		cout << "no fin" << endl;

	// Import the file into the image object
	fin2 >> image;

	// Ensure fin2 is closed
	fin2.close();

	// Create output path for the test PPM
	// This allows us to ensure that the file is loaded and writing correctly
	ofstream fout2(output_path);

	if (!fout2)
		cout << "no fout" << endl;

	// Write the image object to the file
	fout2 << image;

	// Ensure output is closed
	fout2.close();

	// Create output stream for ascii art
	ofstream fout3(ascii_output_path);

	if (!fout3)
		cout << "no fout3" << endl;


	// Print the ascii art to the file
	image.printASCII(fout3);

	return 0; 
}
