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

    Fl_Input *usrStr = nullptr;
    Fl_Input *usrSize = nullptr;
    Fl_Output *res = nullptr;
    Fl_Button *truncateUsrStr = nullptr;
    Fl_Button *quiz = nullptr;

	Fl_Window *window = new Fl_Window(640,360, "Beus's Truncate Application");
    window->begin();
    Fl_Output *stringInputInstructions = new Fl_Output(10, 10, 600, 30, 0);
    stringInputInstructions->value("");
    window->end();
    window->show(argc, argv);

    return Fl::run();

}
