#include<iostream>
#include<vector>
using namespace std;    

int binarySearch2D(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return -1;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols];

        if (midValue == target) {
            return mid; // Target found
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

int main(){
    int rows, cols, target;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }
    cin >> target;      
    int result = binarySearch2D(matrix, target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    } else {        
        cout << "Element not found" << endl;
    }
    return 0;
}