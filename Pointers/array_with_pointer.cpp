#include<iostream>
using namespace std;

int * arrayWithPointer(int size) {
    int *arr = new int[size]; // Dynamically allocate an array of integers
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Initialize the array with values 1 to size
    }
    return arr; // Return the pointer to the allocated array
}

int main() {
    int size = 5; // Size of the array
    int *arr = arrayWithPointer(size); // Get the pointer to the dynamically allocated array

    // Print the elements of the array
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " "; // Using pointer arithmetic to access array elements
    }
    cout << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}