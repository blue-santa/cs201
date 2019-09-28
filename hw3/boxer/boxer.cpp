/**
 * boxer.cpp
 * CS 201
 * Bryan Beus
 * September 28, 2019
 * The main file for the boxer program
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "boxer.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::noskipws;
using std::getline;

int main (int argc, char **argv) { 

    string phrase;
    int layers;
    bool contLoop = true;

    while (contLoop) {
        clearConsole(); 

        requestLayers(layers, contLoop); 

        if (contLoop) {
            requestPhrase(phrase);
            printWord(layers, phrase);
            waitForContinue();
        } else {
            break;
        } 
    } 

    return 0;
}
