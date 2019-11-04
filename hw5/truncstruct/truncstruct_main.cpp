/* 
* trunstruct_main.cpp 
* Bryan Beus 
* CS 201 
* October 23, 2019 
* Main file for trunstruct lab22 
*/

#include <iostream> 
#include <string> 
#include <vector> 
#include <sstream> 

#include "truncstruct.hpp"
#include "beus_truncstruct.hpp"

#include <FL/Fl.H> 
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

using std::string; 
using std::istringstream; 

int main(int argc, char **argv) {

    // Declare Fl_Output pointer objects for displaying instructions and information
    Fl_Output *stringInputDisplay = nullptr;
    Fl_Output *countPrompt = nullptr;
    Fl_Output *resultDisplay = nullptr;

    // Delcare Fl objects for representing display
    Fl_Input *usrStr = nullptr;
    Fl_Input *usrCount = nullptr;
    Fl_Output *res = nullptr;
    Fl_Button *truncateUsrStr = nullptr;
    Fl_Button *quit = nullptr;

    // Declare FLTK Window
	Fl_Window *window = new Fl_Window(640,170, "Beus's Truncate Application");
    window->begin();

    // Declare initial window outputs and inputs for child 0 and 1
    stringInputDisplay = new Fl_Output(10, 10, 270, 25, 0);
    stringInputDisplay->value("Please provide a string to truncate:"); 
    usrStr = new Fl_Input(290, 10, 340, 25);

    // Declare initial values for output and input of child 2 and 3
    countPrompt = new Fl_Output(10, 50, 270, 25, 0);
    countPrompt->value("How many final integers?"); 
    usrCount = new Fl_Input(290, 50, 340, 25);

    // Delcare initial values of childs 4 and 5
    resultDisplay = new Fl_Output(10, 90, 270, 25, 0);
    resultDisplay->value("The truncated string:"); 
    res = new Fl_Output(290, 90, 340, 25, 0);

    // Declare buttons for user actions
    truncateUsrStr = new Fl_Button(10, 130, 130, 25, "Truncate");
    truncateUsrStr->callback(truncArbitrary);

    quit = new Fl_Button(150, 130, 130, 25, "Quit");
    quit->callback(quitProgram);

    // End window
    window->end();
    window->show(argc, argv);

    // Launch window
    return Fl::run();

}


