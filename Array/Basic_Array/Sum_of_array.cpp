#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    };
};

int Sum_of_array(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[20];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The elements in the array are: ";
    printArray(arr, n);
    cout<<endl;
    cout<<"The Sum of elements in the array is: "<<Sum_of_array(arr, n)<<endl;
    return 0;
}