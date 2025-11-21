#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[i], arr[minIndex]);//swap function inbuilt in C++
            // int temp = arr[i];
            // arr[i] = arr[minIndex];
            // arr[minIndex] = temp;
        }
    }
}

int main(){
    int arr[10] = {64, 25, 12, 22, 11};
    int n = 5; 
    cout<<"Original array: ";
    printArray(arr, n);
    selectionSort(arr, n);
    cout<<"Selection Sort: "<<endl;
    printArray(arr, n);
    return 0;
}