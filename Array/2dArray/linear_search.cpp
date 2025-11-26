#include<iostream>
using namespace std;    

int main(){
    int n, m, target;   
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    int arr[100][100];
    cout << "Enter elements of the array:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }       
    cout << "Enter the target element to search: ";
    cin >> target;
    bool found = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == target){
                cout << "Element found at position (" << i << ", " << j << ")" << endl;
                found = true;
                break;
            }
        }
    if(!found){
        cout << "Element not found in the array." << endl;
    }
}
    return 0;
} 