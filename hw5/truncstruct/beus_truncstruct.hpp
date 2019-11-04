/*
 * beus_truncstruct.hpp
 * Bryan Beus
 * CS 201
 * November 3, 2019
 * Beus's header file for adapted functions
 */

#ifndef FILE_BEUS
#define FILE_BEUS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "truncstruct.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

using std::string;
using std::istringstream;

// Quit the program
void quitProgram(Fl_Widget* obj, void*);

// Truncate a user-provided arbitrary number of characters from a string
void truncArbitrary(Fl_Widget* obj, void*);

#endif //#ifndef FILE_BEUS

