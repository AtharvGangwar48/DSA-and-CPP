// Priority Queue Implementation
// Use Case: Task scheduling, Dijkstra's algorithm, emergency systems

#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int data;
    int priority;
    Element(int d, int p) : data(d), priority(p) {}
};

class PriorityQueue {
private:
    vector<Element> heap;
    
    void heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].priority <= heap[parent].priority) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }
    
    void heapify_down(int index) {
        int size = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            
            if (left < size && heap[left].priority > heap[largest].priority)
                largest = left;
            if (right < size && heap[right].priority > heap[largest].priority)
                largest = right;
            
            if (largest == index) break;
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }
    
public:
    void enqueue(int data, int priority) {
        heap.push_back(Element(data, priority));
        heapify_up(heap.size() - 1);
    }
    
    int dequeue() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        int data = heap[0].data;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapify_down(0);
        return data;
    }
    
    int peek() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return heap[0].data;
    }
    
    bool is_empty() { return heap.empty(); }
    
    void display() {
        for (auto& elem : heap)
            cout << "(" << elem.data << "," << elem.priority << ") ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 5);
    pq.enqueue(30, 1);
    pq.display();  // (20,5) (10,2) (30,1)
    
    cout << "Dequeued: " << pq.dequeue() << endl;  // 20 (highest priority)
    cout << "Peek: " << pq.peek() << endl;         // 10
    return 0;
}