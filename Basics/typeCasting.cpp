#include <iostream>
using namespace std;

int main() {
    char a = 97; // ASCII value of 'a'
    int b = 'b';   // Implicit casting from char to int

    cout << "Character a (Actual input a=97): " << a << endl; // Outputs: a
    cout << "Integer b (Actual input b='b'): " << b << endl; // Outputs: 97
    return 0;
}