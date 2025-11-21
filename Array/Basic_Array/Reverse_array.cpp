#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    };
};

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
};

void reverseArray(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    };
};

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[100]; // assuming maximum size of array is 100
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"The elements in the array (Before Reversal): ";
    printArray(arr, n);
    cout<<endl; 
    reverseArray(arr, n);   
    cout<<"The elements in the array (After Reversal): ";
    printArray(arr, n);
    cout<<endl;
    return 0;
}