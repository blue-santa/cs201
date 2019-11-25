// Color3.cpp
// Implementation for Color3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include <iomanip>
#include "Color3.hpp"
#include <fstream>
#include <sstream>

#define MAXVAL 255

using std::setw;
using std::cout;
using std::cin;
using std::endl;

// Ensure values are in the range 0 to maxvalue
constexpr int saturate(int x, int maxvalue) {
	return x < 0 ? 0 : x > maxvalue ? maxvalue : x;
}

Color3::Color3()
	: r(255), g(255), b(255)
{ }

Color3::Color3(int R, int G, int B) {
	r = (unsigned char)saturate(R, 255);
	g = (unsigned char)saturate(G, 255);
	b = (unsigned char)saturate(B, 255);
}

int Color3::weightedSum() const {
	// Implement Y = 0.2126R + 0.7152G + 0.0722B
	// Ensure values are inside the range 0 to 255

	int temp_r = 0.2126 * saturate((int)r, MAXVAL);
	int temp_g = 0.7152 * saturate((int)g, MAXVAL);
	int temp_b = 0.0722 * saturate((int)b, MAXVAL);

	// if (saturate(Y))

	int weightedsum = saturate(temp_r + temp_g + temp_b, MAXVAL);

	return weightedsum;
}

char Color3::asciiValue() const {
	// Use at least 16 characters, sort these from dark to light
	// or light to dark and then map the weightedSum() to the range
	// 0 to 15. Please pick your own characters
	const char values[] = "0$PX@Iwocv:+~,' ";
	
	// .'`,^:";~
	// -_+<>i!lI?
	// /\|()1{}[]
	// rcvunxzjft
	// LCJUYXZO0Q
	// *WMB8&%$#@

	// Find the weighted sum of the r, g, b values for this asciiValue
	int w_sum = weightedSum();

	// Divide by 15 to eliminate color data and reduce to value data only 
	w_sum = w_sum / 15;

	// Get remainder to determine position in values[] array 
	unsigned darkness = w_sum % 15;

	// Return ascii character matching value of computation of weightedsum
	return values[darkness];
}

// Stream Operators for input and output

std::ostream& operator<<(std::ostream& ostr, const Color3& color) {
	ostr << setw(3) << (int)color.r << " ";
	ostr << setw(3) << (int)color.g << " ";
	ostr << setw(3) << (int)color.b << " ";
	return ostr;
}

std::istream& operator>>(std::istream& istr, Color3& color) {
	// Implement your own input for a Color3

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
