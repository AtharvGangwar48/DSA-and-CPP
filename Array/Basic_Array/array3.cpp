#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    };
};

int main(){
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int arr[100]; // assuming maximum size of array is 100
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    printArray(arr, n);
    cout<<endl; 
    cout<<"Length of array: "<<sizeof(arr)/sizeof(int)<<endl; // This will give length of array not number of elements
    return 0;
}
