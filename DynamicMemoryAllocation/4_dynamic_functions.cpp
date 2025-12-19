#include<iostream>
using namespace std;

// Function that returns dynamically allocated array
int* createArray(int size){
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = i * i; // Square numbers
    }
    return arr;
}

// Function that takes dynamic array as parameter
void printArray(int *arr, int size){
    cout << "Array elements: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to resize array (create new, copy, delete old)
int* resizeArray(int *oldArr, int oldSize, int newSize){
    int *newArr = new int[newSize];
    
    // Copy old elements
    int copySize = (oldSize < newSize) ? oldSize : newSize;
    for(int i = 0; i < copySize; i++){
        newArr[i] = oldArr[i];
    }
    
    // Initialize new elements if array is larger
    for(int i = oldSize; i < newSize; i++){
        newArr[i] = 0;
    }
    
    delete[] oldArr; // Delete old array
    return newArr;
}

int main(){
    int size = 5;
    
    // Create dynamic array using function
    int *arr = createArray(size);
    cout << "Original array:" << endl;
    printArray(arr, size);
    
    // Resize array to larger size
    int newSize = 8;
    arr = resizeArray(arr, size, newSize);
    cout << "\nAfter resizing to " << newSize << ":" << endl;
    printArray(arr, newSize);
    
    // Resize array to smaller size
    int smallerSize = 3;
    arr = resizeArray(arr, newSize, smallerSize);
    cout << "\nAfter resizing to " << smallerSize << ":" << endl;
    printArray(arr, smallerSize);
    
    // Clean up
    delete[] arr;
    
    return 0;
}