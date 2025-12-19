#include<iostream>
using namespace std;

int main(){
    int rows = 3, cols = 4;
    
    // Method 1: Array of pointers
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }
    
    // Initialize 2D array
    int value = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = value++;
        }
    }
    
    // Print 2D array
    cout << "2D Array:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // Delete 2D array
    for(int i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
    
    // Method 2: Single allocation (more efficient)
    int *flatArr = new int[rows * cols];
    
    // Access as 2D: flatArr[i * cols + j]
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            flatArr[i * cols + j] = (i + 1) * (j + 1);
        }
    }
    
    cout << "\nFlat 2D Array:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << flatArr[i * cols + j] << " ";
        }
        cout << endl;
    }
    
    delete[] flatArr;
    
    return 0;
}