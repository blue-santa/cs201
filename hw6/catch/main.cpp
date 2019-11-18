#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
#include <string>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <numeric>

// Make M_PI available for calls to the value of pi
#define _USING_MATH_DEFINES

// Initialize and include Catch test suite
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::sin;
using std::atan2;
using std::accumulate;
using std::inner_product;
using std::vector;

// Declare primary TEST_CASE
TEST_CASE( "Common math functions perform", "[math]" ) {

	// Initialize intended value of sin
	double sinVal = sin(M_PI);

	// Initialize intended value of call to atan2()
	double x, y, atan2Val;
	atan2Val = atan2 (x, y) * 180 / M_PI;

	// Initialize intended value of call to accumulate()
	int init = 100;
	vector<int> accPreVals{10, 20, 30, 40};
	int accVal = accumulate(accPreVals.begin(), accPreVals.end(), init);
		
	
	// Initialize intended value of call to inner_product()
	vector<int> a {0, 1, 2, 3, 4};
	vector<int> b {5, 6, 7, 8, 9};
	int innProVal = inner_product(a.begin(), a.end(), b.begin(), 0);


	// Use Catch test suite to test the expected values against the values in practice
	REQUIRE( sin(M_PI) == sinVal );
	REQUIRE( atan2 (x, y) * 180 / M_PI == atan2Val );
	REQUIRE( accumulate(accPreVals.begin(), accPreVals.end(), init) == accVal );
	REQUIRE( inner_product(a.begin(), a.end(), b.begin(), 0) == innProVal );
}
 
