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

// Quit the program
void quitProgram(Fl_Widget* obj, void*) {
    exit(0);
}

// Truncate and capitalize a string according to provided user input of size
void truncArbitrary(Fl_Widget* obj, void*) { 
    
    // Capture the current state of objects when the truncate button is clicked 
    Fl_Button* onButtonClick = (Fl_Button*) obj;

    // Capture the string the user would like to truncate
    Fl_Input* usrStr = (Fl_Input*) onButtonClick->parent()->child(1);

    // Capture the number of integers the user would like the final result truncated to
    Fl_Input* usrCount = (Fl_Input*) onButtonClick->parent()->child(3);

    // Declare variables for prepping call to truncArbitrary()
    size_t usrSize;
    string sendStr;
    string tempStr;

    // Set sendStr to the user's provided string
    sendStr = usrStr->value(); 

    // Set the tempStr to the string-value of integers the user would like to send
    tempStr = usrCount->value();

    // Use istringstream to convert the value to an integer
    istringstream instream(tempStr); 
    instream >> usrSize;

    // Call the trunc() function provided by lab21 default
    StringInfo defaultOutput = trunc(StringInfo { sendStr, usrSize });

    // Capture the child object that displays the final result (currently empty)
    Fl_Output* res = (Fl_Output*) onButtonClick->parent()->child(5);

    // Set the res variable from the window to the final string
    res->value(defaultOutput.str.c_str());
}

