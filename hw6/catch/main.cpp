#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
#include <string>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <numeric>

#define _USING_MATH_DEFINES

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

TEST_CASE( "Common math functions perform", "[math]" ) {

	double sinVal = sin(M_PI);

	double x, y, atan2Val;
	atan2Val = atan2 (x, y) * 180 / M_PI;

	int init = 100;
	vector<int> accPreVals{10, 20, 30, 40};
	int accVal = accumulate(accPreVals.begin(), accPreVals.end(), init);
		
	
	vector<int> a {0, 1, 2, 3, 4};
	vector<int> b {5, 6, 7, 8, 9};
	int innProVal = inner_product(a.begin(), a.end(), b.begin(), 0);

    REQUIRE( sin(M_PI) == sinVal );
    REQUIRE( atan2 (x, y) * 180 / M_PI == atan2Val );
    REQUIRE( accumulate(accPreVals.begin(), accPreVals.end(), init) == accVal );
    REQUIRE( inner_product(a.begin(), a.end(), b.begin(), 0) == innProVal );
}
 
