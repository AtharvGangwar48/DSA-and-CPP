#include<iostream>
using namespace std;

int main(){
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    int arr[n][m];
    cout << "Enter elements of the array:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int maxSum = INT_MIN;
    int rowIndex = -1;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += arr[i][j];
        }
        if(sum > maxSum){
            maxSum = sum;
            rowIndex = i;
        }
    }
    cout << "The largest row sum is " << maxSum << " found in row " << rowIndex << endl;
    return 0;
}