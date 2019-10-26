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

    string usrStr; 
    cout << "Please provide a string: ";

    while(true) {

        getline(cin, usrStr);

        if (!cin || cin.fail()) { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Try again: "; 
        } else { 
            break; 
        }

    }

    StringInfo res; 
    res = trunc8(usrStr);

    cout << res.str << endl; 

    return 0;

}
