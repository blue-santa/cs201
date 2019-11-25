// Image3.hpp
// Implementation for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course

#include "Image3.hpp"
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

using std::ifstream;
using std::ofstream;

// Image3 Constructor
Image3::Image3(unsigned width, unsigned height) {
	// TODO: resize the pixels array

	pixels.resize(width * height);

	// TODO: initialize the internal w and h members

	w = width;
	h = height; 

}

// Return a pixel from the image
const Color3& Image3::getPixel(unsigned x, unsigned y) const {
	// Convert (x,y) coordinate from 2D image to 1D vector format
	unsigned temp = y * w + x;

	// Test if the pixel location is actually available in the pixels array 
	if (temp > pixels.size()) {

		// If we are outside of the available pixels, return a default Color3 object
		return Color3(0, 0, 0); 
	}

	// Otherwise, return the appropriate pixel from the pixels array
	return pixels[y * w + x];
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) {
	
	// Set the pixel to the new color 
	pixels[y * w + x] = color; 
}

bool Image3::savePPM(const std::string& path) const {
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	return false;
}

bool Image3::loadPPM(const std::string& path, std::string& file_contents) {
	// TODO: Load an image from the disk
	// REQUIREMENT: Use the STREAM operators for the file contents

	ifstream fin (path);

	if (!fin) { 
		cout << "Error opening file: " << path << endl; 

		// ensure program stops 
		return false; 
	} 

	string verify_ppm;
	getline(fin, verify_ppm);

	if (verify_ppm != "P3")
		return false;

	// Need to handle ("#") comments

	int temp_w;
	int temp_h;
	string temp_wh;

	getline(fin, temp_wh); 
	istringstream instr_wh(temp_wh);

	if (!instr_wh)
		return false;

	instr_wh >> temp_w;
	if ((typeid(int) != typeid(temp_w)) || temp_w < 0)
	       return false;	

	instr_wh >> temp_h;
	if ((typeid(int) != typeid(temp_h)) || temp_h < 0)
	       return false;	
	
	w = (unsigned)temp_w;
	h = (unsigned)temp_h;

	string maxval_temp;
	getline(fin, maxval_temp);
	istringstream instr_maxval(maxval_temp);

	if (!instr_maxval)
		return false;

	// Can consider making the #define MAXVAL here instead something pulled from the value below
	int maxval;
	instr_maxval >> maxval;
	
	while (!fin.eof()) {

		int temp_r;
	       	int temp_g;
	       	int temp_b;

		for (int i = 0; i < 3; i++) {
			fin >> temp_r;
			fin >> temp_g;
			fin >> temp_b; 
		}

		pixels.push_back(Color3(temp_r, temp_g, temp_b)); 

	}

	return true;
}

void Image3::printASCII(std::ostream& ostr) const {
	// TODO: Print an ASCII version of this image

	ostr << "P3\n";
	ostr << w << " " << h << "\n";
	ostr << 255;
	
	for (size_t i = 0; i < pixels.size(); i++) {
		ostr << pixels[i].asciiValue(); 

		if (i != 0 && i % w == 9) {
			ostr << "\n"; 
		}
	} 
}

// STREAM OPERATORS for IMAGE3 class 
std::ostream& operator<<(std::ostream& ostr, const Image3& image) {
	// TODO: Write out PPM image format to stream
	// ASSUME FORMAT WILL BE GOOD

	// Add line formatting
	ostr << "P3\n";

	// Add dimensions
	ostr << image.w << " " << image.h << "\n";

	// Add max value
	ostr << 255;

	for (size_t i = 1; i <= image.pixels.size(); i++) { 

		// Insert the next pixel value
		ostr << image.pixels[i - 1]; 

		// Add a new line every three values, for formatting
		if (i % 3 == 0) 
			ostr << "\n"; 
	}

	return ostr;
}

std::istream& operator>>(std::istream& istr, Image3& image) {
	// TODO: Read in PPM image format from stream
	// MAKE SURE FORMAT IS GOOD!!!


	// Need to handle comments
	string temp_format;
	istr >> temp_format;

	if (temp_format != "P3") {
		cout << "Error reading file - incorrect format type (P3 expected)" << endl;
		return istr;
	}

	int temp_w;
       	int temp_h;
	string temp_wh;

	getline(istr, temp_wh); 
	istringstream instr_wh(temp_wh);

	if (!instr_wh)
		return istr;

	instr_wh >> temp_w;
	if ((typeid(unsigned) != typeid(temp_w)) || temp_w < 0)
	       return istr;	

	instr_wh >> temp_h;
	if ((typeid(unsigned) != typeid(temp_h)) || temp_h < 0)
	       return istr;	
	
	image.w = (unsigned)temp_w;
	image.h = (unsigned)temp_h;

	string maxval_temp;
	getline(istr, maxval_temp);
	istringstream instr_maxval(maxval_temp);

	
	int maxval;
	instr_maxval >> maxval; 

	while (!istr.eof()) {

		int temp_r;
	       	int temp_g;
	       	int temp_b;

		for (int i = 0; i < 3; i++) {
			istr >> temp_r;
			istr >> temp_g;
			istr >> temp_b; 
		}

		image.pixels.push_back(Color3(temp_r, temp_g, temp_b)); 

	} 

	return istr;
}
