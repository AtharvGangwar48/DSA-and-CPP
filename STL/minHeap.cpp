#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minpq; // min-heap

    minpq.push(40);
    minpq.push(10);
    minpq.push(30);
    minpq.push(20);

    cout << "Priority Queue (Min-Heap): ";
    while(!minpq.empty()) {
        cout << minpq.top() << " ";  // smallest element first
        minpq.pop();
    }
    return 0;
}
