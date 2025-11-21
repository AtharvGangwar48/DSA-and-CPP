#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[10] = {64, 25, 12, 22, 11};
    int n = 5;          
    cout << "Original array: ";   
    printArray(arr, n);
    cout << "Insertion Sort: " << endl;
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}

