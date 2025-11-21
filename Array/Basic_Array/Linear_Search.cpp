#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int Linear_Search(int arr[],int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            cout<<"Key found at index: "<<i<<endl;
            return i;
        }
    }
    cout<<"Key not found"<<endl;
    return -1;
}

int main(){
    int n,key;
    cout<<"Enter the size of array: : ";
    cin>>n;
    int arr[20];
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    printArray(arr,n);
    cout<<"The elements in the array are: ";
    cout<<"Enter the key to be searched: ";
    cin>>key;
    Linear_Search(arr,n,key);
    return 0;
}