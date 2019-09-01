#include <iostream>
#include <string>
using namespace std;

int main() {

    // Declare a string variable for "Hello world"
    string hello = "Hello, World";

    // Initiate a counting sequence for iteration
    int count = 0;

    while (count != 5) {
        
        // Print string to console
        cout << hello << endl;

        // Increase count each time
        count += 1;
    }

    return 0;
}
