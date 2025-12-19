// Merge Sort - Divide and Conquer
// Use Case: Sorting large datasets, external sorting, stable sorting

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    
    for (int i = 0; i < temp.size(); i++)
        arr[left + i] = temp[i];
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    merge_sort(arr, 0, arr.size() - 1);
    
    for (int num : arr)
        cout << num << " ";
    cout << endl;  // 3 9 10 27 38 43 82
    return 0;
}
