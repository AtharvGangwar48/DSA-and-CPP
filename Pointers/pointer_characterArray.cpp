#include<iostream>
using namespace std;

char * pointerCharacterArray() {
    char *arr = new char[6]; // Dynamically allocate an array of characters
    arr[0] = 'H';
    arr[1] = 'e';
    arr[2] = 'l';
    arr[3] = 'l';
    arr[4] = 'o';
    arr[5] = '\0'; // Null-terminate the string
    return arr; // Return the pointer to the allocated array
}

int main() {
    char *arr = pointerCharacterArray(); // Get the pointer to the dynamically allocated character array

    // Print the characters in the array
    for (int i = 0; *(arr + i) != '\0'; i++) {
        cout << *(arr + i); // Using pointer arithmetic to access array elements
    }
    cout << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}