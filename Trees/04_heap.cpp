// Heap - Min Heap and Max Heap implementation
#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> h;
    void heapifyUp(int i) {
        while (i > 0 && h[(i-1)/2] > h[i]) {
            swap(h[(i-1)/2], h[i]);
            i = (i-1)/2;
        }
    }
    void heapifyDown(int i) {
        int n = h.size(), smallest = i;
        int l = 2*i+1, r = 2*i+2;
        if (l < n && h[l] < h[smallest]) smallest = l;
        if (r < n && h[r] < h[smallest]) smallest = r;
        if (smallest != i) { swap(h[i], h[smallest]); heapifyDown(smallest); }
    }
public:
    void insert(int val) { h.push_back(val); heapifyUp(h.size()-1); }
    int extractMin() {
        int mn = h[0];
        h[0] = h.back(); h.pop_back();
        if (!h.empty()) heapifyDown(0);
        return mn;
    }
    int peek() { return h[0]; }
    void print() { for (int x : h) cout << x << " "; cout << "\n"; }
};

// Heap Sort using max-heap (STL)
void heapSort(vector<int>& arr) {
    priority_queue<int> pq(arr.begin(), arr.end());
    for (int i = arr.size()-1; i >= 0; i--) {
        arr[i] = pq.top(); pq.pop();
    }
}

int main() {
    MinHeap mh;
    for (int x : {5, 3, 8, 1, 9, 2}) mh.insert(x);
    cout << "Min Heap: "; mh.print();
    cout << "Extract min: " << mh.extractMin() << "\n";
    cout << "After extract: "; mh.print();

    vector<int> arr = {5, 3, 8, 1, 9, 2};
    heapSort(arr);
    cout << "Heap Sort: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
}
