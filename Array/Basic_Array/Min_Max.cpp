#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int Maximum(int arr[],int size){
    int max = INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int Minimum(int arr[],int size){
    int min = INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cout<<"Enter the element "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"The elements in the array are: ";
    printArray(arr, 10);
    cout<<endl;
    cout<<"The Maximum element in the array is: "<<Maximum(arr,10)<<endl;
    cout<<"The Minimum element in the array is: "<<Minimum(arr,10)<<endl;
    return 0;
}