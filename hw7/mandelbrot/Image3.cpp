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
		return pixels[0];
	}

	// Otherwise, return the appropriate pixel from the pixels array
	return pixels[y * w + x];
}

// Set a pixel to a new color
void Image3::setPixel(unsigned x, unsigned y, const Color3& color) { 
	// Set the pixel to the new color 
	pixels[y * w + x] = color; 
}

// Save a ppm file to an output filestream
bool Image3::savePPM(const std::string& path) const {
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	ofstream fout (path);

	if (!fout)
		return false;

	fout << *this;
	return true;
}

// Load a PPM file from a file path
bool Image3::loadPPM(const std::string& path, std::string& file_contents) {
	// TODO: Load an image from the disk
	// REQUIREMENT: Use the STREAM operators for the file contents

	ifstream fin (path);

	if (!fin) {
		return false;
	}

	fin >> *this;

	return true;
}

// Send an ascii version of an image object to an output stream
void Image3::printASCII(std::ostream& ostr) const {
	// TODO: Print an ASCII version of this image

	for (size_t i = 0; i < pixels.size(); i++) {
		ostr << pixels[i].asciiValue(); 

		// When reaching the end of a row, make sure to start a new line
		if ((i + 1) % w == 0 && i != 0) {
			ostr << "\n";
		}
	} 
}

// STREAM OPERATORS for IMAGE3 class 
std::ostream& operator<<(std::ostream& ostr, const Image3& image) {
	// Add line formatting
	ostr << "P3\n";

	// Add dimensions
	ostr << image.w << " " << image.h << "\n";

	// Insert the next pixel value
	for (size_t i = 0; i < image.pixels.size(); i++) { 
		ostr << image.pixels[i] << "\n"; 
	}

	return ostr;
}

// When sending an input stream to an image object, format as follows
std::istream& operator>>(std::istream& istr, Image3& image) {
	// TODO: Read in PPM image format from stream
	// MAKE SURE FORMAT IS GOOD!!!

	// Initiate variable to track the first three rows for formatting
	int first_three_vals = 0;

	// Declare persistent rgb variables to track the progress through each line (in case the lines are not formatted with 3 values to a row
	int temp_r = -1;
	int temp_g = -1;
	int temp_b = -1;

	// Initiate endless while loop for duration of stream
	while (true) {
		// Capture current line
		string line;
		getline(istr, line);

		// If the stream is empty, cease the while loop
		if (!istr)
			break;

		// Ignore comments
		if (line.at(0) == '#')
			continue;

		// Check the formatting is P3
		if (first_three_vals == 0) {
			if (line == "P3") {
				first_three_vals++;
				continue;
			} else {
				return istr;
			}
		}
			
		// Initiate the w/h values
		if (first_three_vals == 1) {
			int temp_w;
			int temp_h;
			istringstream instr_wh(line);

			if (!instr_wh)
				return istr;

			instr_wh >> temp_w;
			if (temp_w < 0)
			       return istr;	

			instr_wh >> temp_h; 
			if (temp_h < 0)
			       return istr;	
			
			image.w = (unsigned)temp_w;
			image.h = (unsigned)temp_h; 
			first_three_vals++;
			continue;
		} 

		// Ignore max value line
		if (first_three_vals == 2) {
			istringstream instr_maxval(line);

			if (!instr_maxval)
				return istr;

			int maxval;
			instr_maxval >> maxval;
	

			first_three_vals++;
			continue;
		}

		// Use a string stream to convert a string to an int more easiy
		istringstream instr_rgb(line); 

		// Load the next value into an r, g, or b persistent variable
		if (temp_r == -1) {
			instr_rgb >> temp_r; 
		} else if (temp_g == -1 && temp_r != -1) {
			instr_rgb >> temp_g; 
		} else if (temp_b == -1 && temp_r != -1 && temp_g != -1) {
			instr_rgb >> temp_b; 

			// Once all three are loaded, add the combination to the pixels vector
			image.pixels.push_back(Color3(temp_r, temp_g, temp_b)); 
		} 
		
		// If all three persistent variables are loaded, reset to start again
		if (temp_b != -1 && temp_r != -1 && temp_g != -1) {
			temp_r = -1;
			temp_g = -1;
			temp_b = -1;
		} 
	}

	return istr;
}
