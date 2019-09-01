#include <iostream>
#include <string>
using namespace std;

int main() {

    string hello = "Hello, World";
    int count = 0;

    while (count != 5) {
        
        cout << hello << endl;
        count += 1;
    }

    return 0;
}
