#include<iostream>
using namespace std;

int arraySum(int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(arr + i); // Using pointer arithmetic to access array elements
    }
    return sum;
}   

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = arraySum(arr, size);
    cout << "Sum of array elements: " << sum << endl;   
    return 0;
}