// pointers.cpp
// Glenn G. Chappell
// 9 Apr 2018
//
// For CS 201 Spring 2018
// Programming with Pointers
//
// Modified 11/14/18
// Chris Hartman
// For CS 201 Fall 2018

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


// changeInt
// Given a pointer to int, change the value pointed to.
void changeInt(int * p)  // p points to value to change
{
	if (p != nullptr)
		*p = 7;
}


int main()
{
    int ss = 3;
    int tt = 4;

    cout << "START" << endl;
    cout << "Value of ss: " << ss << endl;
    cout << "Value of tt: " << tt << endl;
    cout << endl;

    int * ip = nullptr;

    // *** HERE, ADD CODE THAT USES ip to modify variables ss and tt

	ip = &ss;
	*ip = 5;

	ip = &tt;
	*ip = 6;

    cout << "AFTER USING ip" << endl;
    cout << "Value of ss: " << ss << endl;
    cout << "Value of tt: " << tt << endl;
    cout << endl;

    // *** UNCOMMENT AND COMPLETE THE FOLLOWING LINE

    ip = &ss;
    
    changeInt( ip );  // Pass a pointer to ss to function changeInt

    cout << "AFTER CALLING changeInt" << endl;
    cout << "Value of ss: " << ss << endl;
    cout << endl;

    ip = nullptr;

    cout << "Value of ip after set to nullptr:" << endl;
    cout << ip << endl;
    cout << endl;

    changeInt( ip);

    cout << "Value of ip after call to changeInt: " << endl;
    cout << ip << endl;
    cout << endl;

    // Wait for user
    cout << "PRESS ENTER ";
    while (cin.get() != '\n') ;

    return 0;
}

