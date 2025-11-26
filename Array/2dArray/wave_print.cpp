#include<iostream>
using namespace std;

void wavePrint(int arr[][100], int n, int m){
    for(int j = 0; j < m; j++){
        if(j % 2 == 0){
            // Print downwards
            for(int i = 0; i < n; i++){
                cout << arr[i][j] << " ";
            }
        } else {
            // Print upwards
            for(int i = n - 1; i >= 0; i--){
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

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
    return 0;
}