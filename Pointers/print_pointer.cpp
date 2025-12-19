#include<iostream>
using namespace std;    

void printPointer(int *ptr) {
    cout << "Pointer address: " << ptr << endl; // Print the address stored in the pointer
    cout << "Value at pointer: " << *ptr << endl; // Dereference the pointer to get the value
}

int main() {
    int value = 42; // An integer variable
    int *ptr = &value; // Pointer to the integer variable

    printPointer(ptr); // Call the function to print pointer information

    return 0;
}