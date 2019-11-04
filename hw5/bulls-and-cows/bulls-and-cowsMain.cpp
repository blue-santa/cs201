/**
 * bulls-and-cowsMain.cpp
 * CS 201
 * Bryan Beus
 * October 15, 2019
 * The main file for bulls-and-cows
 */ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>
#include <stdlib.h>

#include "bulls-and-cows.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;
using std::find;
using std::istringstream;
using std::stringstream;
using std::ifstream;
using std::rand;

int main(int argc, char **argv) {

    // Initiate a string to hold the correct pattern
    string pattern = "";

    // Call the setPattern function to set the pattern
    setPattern(pattern);

    // Declare Fl_Output pointer objects for displaying instructions and information
    Fl_Output *currentGuessDisplay = nullptr;
    Fl_Output *resultCowsDisplay = nullptr;
    Fl_Output *resultBullsDisplay = nullptr;

    // Delcare Fl objects for representing display
    Fl_Input *usrGuess = nullptr;
    Fl_Output *resCows = nullptr;
    Fl_Output *resBulls = nullptr;
    Fl_Output *correctPattern = nullptr;
    

    // Declare buttons
    Fl_Button *calculateRes = nullptr;
    Fl_Button *quit = nullptr;

    // Declare FLTK Window
	Fl_Window *window = new Fl_Window(640,170, "Beus's Truncate Application");
    window->begin();

    // Declare text and output for user guesses, childs 0 and 1
    currentGuessDisplay = new Fl_Output(10, 10, 270, 25, 0);
    currentGuessDisplay->value("Guess the pattern of four integers:");
    usrGuess = new Fl_Input(290, 10, 340, 25);

    // Declare initial values of childs 2 and 3
    resultCowsDisplay = new Fl_Output(10, 50, 270, 25, 0);
    resultCowsDisplay->value("Cows:");
    resCows = new Fl_Output(290, 50, 340, 25, 0);

    // Declare initial values of childs 4 and 5
    resultBullsDisplay = new Fl_Output(10, 90, 270, 25, 0);
    resultBullsDisplay->value("Bulls:");
    resBulls = new Fl_Output(290, 90, 340, 25, 0);

    // Declare correct pattern as child 6
    correctPattern = new Fl_Output(10,10,0,0,0);
    correctPattern->value(pattern.c_str());

    // Declare buttons for user actions
    calculateRes = new Fl_Button(10, 130, 130, 25, "Calculate");
    calculateRes->callback(calculateBullsAndCows);

    quit = new Fl_Button(150, 130, 130, 25, "Quit");
    quit->callback(quitProgram);

    // End window
    window->end();
    window->show(argc, argv);

    // Launch window
    return Fl::run(); 
}
