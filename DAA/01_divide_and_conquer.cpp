// DAA - Divide and Conquer: Merge Sort, Quick Sort, Binary Search
#include <bits/stdc++.h>
using namespace std;

// Merge Sort - O(n log n)
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> left(arr.begin()+l, arr.begin()+mid+1);
    vector<int> right(arr.begin()+mid+1, arr.begin()+r+1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

// Quick Sort - O(n log n) avg
int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l - 1;
    for (int j = l; j < r; j++)
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    swap(arr[i+1], arr[r]);
    return i + 1;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

// Binary Search - O(log n)
int binarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        arr[mid] < target ? l = mid+1 : r = mid-1;
    }
    return -1;
}

// Count inversions using merge sort
long long countInv(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long inv = countInv(arr, l, mid) + countInv(arr, mid+1, r);
    vector<int> tmp;
    int i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else { inv += (mid - i + 1); tmp.push_back(arr[j++]); }
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = tmp[k-l];
    return inv;
}

int main() {
    vector<int> a = {5, 2, 8, 1, 9, 3};
    mergeSort(a, 0, a.size()-1);
    cout << "Merge Sort: "; for (int x : a) cout << x << " "; cout << "\n";

    vector<int> b = {5, 2, 8, 1, 9, 3};
    quickSort(b, 0, b.size()-1);
    cout << "Quick Sort: "; for (int x : b) cout << x << " "; cout << "\n";

    cout << "Binary Search(8): " << binarySearch(a, 8) << "\n";

    vector<int> c = {2, 4, 1, 3, 5};
    cout << "Inversions: " << countInv(c, 0, c.size()-1) << "\n";
}
