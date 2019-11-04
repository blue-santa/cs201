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
#include <algorithm> 
#include <sstream> 
#include <cmath> 
#include "truncstruct.hpp"
#include <FL/Fl.H> 
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

using std::cout; 
using std::cin; 
using std::endl; 
using std::vector; 
using std::string; 
using std::noskipws; 
using std::getline; 
using std::istringstream; 
using std::ostringstream; 
using std::find;

void quitProgram(Fl_Widget* obj, void*);

int main(int argc, char **argv) {

    // string usrStr; 
    // cout << "Please provide a string: ";

    // while(true) {

        // getline(cin, usrStr);

        // if (!cin || cin.fail()) { 
            // cin.clear(); 
            // cin.ignore(1000, '\n'); 
            // cout << "Try again: "; 
        // } else { 
            // break; 
        // }

    // }

    // size_t usrCount; 
    // cout << "To how many characters would you like to truncate the string? ";

    // while(true) {

	// string temp;
        // getline(cin, temp);

        // if (!cin || cin.fail()) { 
		// cin.clear(); 
		// cin.ignore(1000, '\n'); 
		// cout << "Try again: "; 
        // } else { 
		// istringstream instream(temp);
		// instream >> usrCount;
		// break; 
        // }

    // }

    // StringInfo res; 
    // res = trunc8(usrStr, usrCount);

    // cout << res.str << endl; 

    Fl_Text_Buffer *stringInputBuff = nullptr;
    Fl_Text_Display *stringInputDisplay = nullptr;
    Fl_Output *countPrompt = nullptr;
    Fl_Output *resultDisplay = nullptr;

    Fl_Input *usrStr = nullptr;
    Fl_Input *usrCount = nullptr;
    Fl_Output *res = nullptr;
    Fl_Button *truncateUsrStr = nullptr;
    Fl_Button *quit = nullptr;

	Fl_Window *window = new Fl_Window(640,170, "Beus's Truncate Application");
    window->begin();

    stringInputBuff = new Fl_Text_Buffer();
    stringInputDisplay = new Fl_Text_Display(10, 10, 270, 25);
    stringInputDisplay->buffer(stringInputBuff);
    stringInputBuff->text("Please provide a string to truncate:");

    usrStr = new Fl_Input(290, 10, 340, 25);

    countPrompt = new Fl_Output(10, 50, 270, 25, 0);
    countPrompt->value("How many final integers?");

    usrCount = new Fl_Input(290, 50, 340, 25);

    resultDisplay = new Fl_Output(10, 90, 270, 25, 0);
    resultDisplay->value("The truncated string:");

    res = new Fl_Output(290, 50, 340, 25, 0);

    truncateUsrStr = new Fl_Button(10, 130, 130, 25, "Truncate");
    truncateUsrStr->callback(trunc8);

    quit = new Fl_Button(150, 130, 130, 25, "Quit");
    quit->callback(quitProgram);

    window->end();
    window->show(argc, argv);

    return Fl::run();

}

void quitProgram(Fl_Widget* obj, void*) {
    exit(0);
}
