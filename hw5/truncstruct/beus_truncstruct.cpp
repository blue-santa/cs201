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

void quitProgram(Fl_Widget* obj, void*) {
    exit(0);
}

void truncArbitrary(Fl_Widget* obj, void*) { 
    
    Fl_Button* onButtonClick = (Fl_Button*) obj;
    Fl_Output* res = (Fl_Output*) onButtonClick->parent()->child(5);

    Fl_Input* usrStr = (Fl_Input*) onButtonClick->parent()->child(1);
    Fl_Input* usrCount = (Fl_Input*) onButtonClick->parent()->child(3);

    string tempString = usrCount->value();
    istringstream instream(tempString);

    size_t usrSize;
    instream >> usrSize;

    string sendStr = usrStr->value();

    StringInfo defaultOutput = trunc(StringInfo { sendStr, usrSize });

    res->value(defaultOutput.str.c_str());
}

