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

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) {
	
	// Set the pixel to the new color 
	pixels[y * w + x] = color; 
}

bool Image3::savePPM(const std::string& path) const {
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	ofstream fout (path);

	if (!fout)
		return false;

	fout << *this;
	return true;
}

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

void Image3::printASCII(std::ostream& ostr) const {
	// TODO: Print an ASCII version of this image

	for (size_t i = 0; i < pixels.size(); i++) {
		ostr << pixels[i].asciiValue(); 
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

	// Add max value
	ostr << 255 << "\n";
	cout << "image.pixels.size(): " << image.pixels.size() << endl;

	for (size_t i = 0; i < image.pixels.size(); i++) { 

		// Insert the next pixel value
		ostr << image.pixels[i] << "\n"; 

	}

	return ostr;
}

std::istream& operator>>(std::istream& istr, Image3& image) {
	// TODO: Read in PPM image format from stream
	// MAKE SURE FORMAT IS GOOD!!!

	// Need to handle comments 
	int first_three_vals = 0;
	int temp_r = -1;
	int temp_g = -1;
	int temp_b = -1;

	int count = 0;

	while (true) {
		
		count++;
		string line;
		getline(istr, line);

		if (!istr)
			break;

		if (line.at(0) == '#')
			continue;

		if (first_three_vals == 0) {
			if (line == "P3") {
				first_three_vals++;
				continue;
			} else {
				return istr;
			}
		}
			
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

		if (first_three_vals == 2) {
			istringstream instr_maxval(line);

			if (!instr_maxval)
				return istr;

			// Can consider making the #define MAXVAL here instead something pulled from the value below
			int maxval;
			instr_maxval >> maxval;
	

			first_three_vals++;
			continue;
		}
		cout << "line: " << line << " count: " << count << " pixels.size(): " << image.pixels.size() <<  endl;
		cout << "r: " << temp_r << " g: " << temp_g << " b: " << temp_b << endl; 

		istringstream instr_rgb(line); 

		if (temp_r == -1) {
			instr_rgb >> temp_r; 
		} else if (temp_g == -1 && temp_r != -1) {
			instr_rgb >> temp_g; 
		} else if (temp_b == -1 && temp_r != -1 && temp_g != -1) {
			instr_rgb >> temp_b; 
			image.pixels.push_back(Color3(temp_r, temp_g, temp_b)); 
		} 
		
		if (temp_b != -1 && temp_r != -1 && temp_g != -1) {
			temp_r = -1;
			temp_g = -1;
			temp_b = -1;
		} 
	}
	cout << "image.pixels.size(): " << image.pixels.size() << endl;
	cout << "count: " << count << endl;

	return istr;
}
