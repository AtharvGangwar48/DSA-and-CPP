#include<iostream>
using namespace std;

int ** createDoublePointer(int rows, int cols) {
    // Allocate memory for an array of pointers
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++) {
        // Allocate memory for each row
        arr[i] = new int[cols];
    }
    return arr;
}

void deleteDoublePointer(int **arr, int rows) {
    for(int i = 0; i < rows; i++) {
        // Deallocate each row
        delete[] arr[i];
    }
    // Deallocate the array of pointers
    delete[] arr;
}

int main() {
    int rows = 3, cols = 4;
    // Create a double pointer (2D array)
    int **matrix = createDoublePointer(rows, cols);

    // Initialize and print the 2D array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the memory
    deleteDoublePointer(matrix, rows);
    return 0;
}