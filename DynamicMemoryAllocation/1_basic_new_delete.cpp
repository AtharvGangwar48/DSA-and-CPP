#include<iostream>
using namespace std;

int main(){
    // Basic dynamic memory allocation for single variable
    int *ptr = new int(42);
    cout << "Value: " << *ptr << endl;
    cout << "Address: " << ptr << endl;
    
    // Always delete dynamically allocated memory
    delete ptr;
    
    // Dynamic allocation for array
    int size = 5;
    int *arr = new int[size];
    
    // Initialize array
    for(int i = 0; i < size; i++){
        arr[i] = i * 10;
    }
    
    // Print array
    cout << "Array elements: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Delete array
    delete[] arr;
    
    return 0;
}