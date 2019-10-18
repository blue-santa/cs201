/**
 * @file     L19_Floating_Point.cpp
 * @author   Student Name
 * @version  Jan 28, 2019
 * John Quan 
 *
 * Useful trigonometric functions.
 */

#include <iostream>
#include <vector>
// using sin, cos
#include <cmath>

#include "floating_point.hpp"

using std::cout;
using std::endl;
using std::cos;
using std::sin;

int main() {
	// TODO Turn on "error on warnings" so this doesn't*****************
	// compile.  Make it compile by using std::size_t
	// You can comment this for loop out after that.
	std::vector<int> v { 1, 2, 3, 4, 5 };
	for (size_t i = 2; i < v.size(); ++i) {
		++v[i];
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl << std::endl;
	// *****************************************************************

	// TODO Declare and initialize a vector of radians by calling*******
	//        degreesToRadians(360).
	//      Print degree,cos(radian),sin(radian) as a comma separated
	//        values (CSV) list.

	cout << "degree,cos(radian),sin(radian)" << endl;

	for (size_t i = 1; i <= 360; i++) {
		double radian = i * M_PI / 180.0;

		cout << i << "," << cos(radian) << "," << sin(radian) << endl;
	}

	// *****************************************************************

	double j = 999999999999999999;

	while (j != j + 1) {
		j++;
	}

	cout << "j = " << j << ", and j + 1 = " << j + 1 << ", and these are equal, but they shouldn't be" << endl;
	return 0;
}
