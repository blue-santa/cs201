/*
 * main.cpp
 * Bryan Beus
 * November 24, 2019
 * The main file for the mandelbrot project in hw7
 */

#include <cmath>
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

// Process the mandelbrot image
void process_mandelbrot(Image3& image);

int main() {

	// Set image dimesions
	double scale = 0.2;
	unsigned width = (unsigned)(std::round(5120 * scale));
	unsigned height = (unsigned)(std::round(2098 * scale));

	// Create default image
	Image3 image(width, height);

	// Process the image with mandelbrot calculations
	process_mandelbrot(image);

	// Create output stream and save file
	string output_file("mandelbrot.ppm");
	ofstream fout(output_file);

	if (!fout) {
		cout << "no fout" << endl;
		return 0;
	}

	fout << image;

	return 0;
}

// Process the mandelbrot image
void process_mandelbrot(Image3& image) {

	// Allow for w, h variables in int form
	int w = (int)image.w;
	int h = (int)image.h;

	// For each pixel(Px, Py) on the screen, do:
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {

			// Set x = i iteration
			// Set y = j iteration
			int x = i;
			int y = j;

			// x0 = scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
			double x0 = ( (double)x / (double)w) * 3.5 - 2.5;

			// y0 = scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
			double y0 = ( (double)y / (double)h) * 2 - 1;

			// x = 0.0
			double x_val = 0.0;

			// y = 0.0
			double y_val = 0.0;

			// iteration = 0
			int iteration = 0;

			// max_iteration = 1000
			int max_iteration = 1000;

			// while (x*x + y*y <= 2*2 AND iteration < max+iteration
			while (x_val*x_val + y_val * y_val <= 2*2*2*2 && iteration < max_iteration) {

				// xtemp = x*x - y*y + x0
				double x_temp = (double) x_val*x_val - y_val*y_val + x0;

				// y = 2 * x * y + y0
				double y_temp = (double) 2 * x_val * y_val + y0;
				y_val = y_temp;

				// x = xtemp
				x_val = x_temp;

				// iteration = iteration + 1
				iteration++;
			}


			// color = palette[iteration]
			int r, g, b;
			r = iteration * 15;
			g = r / 3;
			b = g / 2;

			// plot(Px, Py, color)
			image.setPixel(x, y, Color3(r, g, b));
		}
	}
}

