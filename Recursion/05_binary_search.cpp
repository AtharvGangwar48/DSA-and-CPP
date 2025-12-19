// Binary Search - Recursive Implementation
// Use Case: Searching in sorted arrays, database indexing

#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binary_search(arr, target, left, mid - 1);
    else
        return binary_search(arr, target, mid + 1, right);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << binary_search(arr, 7, 0, arr.size() - 1) << endl;   // 3
    cout << binary_search(arr, 10, 0, arr.size() - 1) << endl;  // -1
    return 0;
}
