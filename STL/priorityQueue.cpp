#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;  // max-heap by default

    pq.push(40);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Priority Queue (Max-Heap): ";
    while(!pq.empty()) {
        cout << pq.top() << " ";  // largest element on top
        pq.pop();
    }
    return 0;
}
