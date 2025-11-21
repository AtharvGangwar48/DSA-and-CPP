#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); 
            }
        }
    }
}

int main(){
    int arr[10] = {64, 25, 12, 22, 11};
    int n = 5;          
    cout<<"Original array: ";   
    printArray(arr, n);
    cout<<"Bubble Sort: "<<endl;
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}