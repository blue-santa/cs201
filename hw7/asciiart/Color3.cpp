// Color3.cpp
// Implementation for Color3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>

#include "Color3.hpp"

// Define a max value
#define MAXVAL 255

using std::setw;
using std::cout;
using std::cin;
using std::endl;

// Ensure values are in the range 0 to maxvalue
constexpr int saturate(int x, int maxvalue) {
	// Return either 0, 255, or a valid value between
	return x < 0 ? 0 : x > maxvalue ? maxvalue : x;
}

// A default, empty color object
Color3::Color3()
	: r(0), g(0), b(0)
{ }

// When defining any of the rgb class members, ensure they are within range
Color3::Color3(int R, int G, int B) {
	r = (unsigned char)saturate(R, 255);
	g = (unsigned char)saturate(G, 255);
	b = (unsigned char)saturate(B, 255);
}

// Discover the weighted sum (for dark/light value of an rgb value)
int Color3::weightedSum() const {
	// To keep mathematical accuracy, convert everything to double for the duration of the computation
	// Perform the conversions for the rgb values
	double temp_r = 0.2126 * (double)r;
	double temp_g = 0.7152 * (double)g;
	double temp_b = 0.0722 * (double)b;

	double before = temp_r + temp_g + temp_b;

	// Prepping for int, round the double
	before = std::round(before);

	// Cast to int
	int after = int(before);

	// Ensure value is within proper range
	int weightedsum = saturate(after, MAXVAL);

	return weightedsum;
}

// Find the equivalent ascii value for an associated rgb value
char Color3::asciiValue() const {
	// Use at least 16 characters, sort these from dark to light
	// or light to dark and then map the weightedSum() to the range
	// 0 to 15. Please pick your own characters
	const char values[] = " ',~+:vcowI@XP$";

	// Find the weighted sum of the r, g, b values for this asciiValue
	int w_sum = weightedSum();

	// Divide by 15 to eliminate color data and reduce to value data only 
	w_sum = w_sum / 15;

	// Get remainder to determine position in values[] array 
	unsigned darkness = w_sum % 15;

	// Return ascii character matching value of computation of weightedsum
	return values[darkness];
}

// For each rgb value from the color object going to the output stream, create a white space between each
std::ostream& operator<<(std::ostream& ostr, const Color3& color) {
	ostr << setw(3) << (int)color.r << " ";
	ostr << setw(3) << (int)color.g << " ";
	ostr << setw(3) << (int)color.b << " ";
	return ostr;
}

// For each input line that is going to a color object, separate out each value into the color object's rgb members
std::istream& operator>>(std::istream& istr, Color3& color) {
	int r;
	istr >> r;
	color.r = (r < 0) ? 0 : (r > 255) ? 255: (unsigned char)r; 

	int b;
	istr >> b;
	color.b = (b < 0) ? 0 : (b > 255) ? 255: (unsigned char)b; 

	int g;
	istr >> g;
	color.g = (g < 0) ? 0 : (g > 255) ? 255: (unsigned char)g; 

	return istr;
}
