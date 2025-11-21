#include<iostream>
using namespace std;

int max_occurence(char arr[], int n) {
    int maxCount = 0;
    char maxChar = arr[0];

    for(int i = 0; i < n; i++) {
        int count = 1;
        for(int j = i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
    }
    return maxChar;
}

int main(){
    char arr[] = {'a', 'b', 'c', 'a', 'b', 'a', 'a'};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Character with maximum occurrence: " << max_occurence(arr, n) << endl;
    return 0;
}