// Queue Implementation using Array
// Use Case: Process scheduling, breadth-first search, buffer for data streams

#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int* arr;
    int front, rear, capacity, size;
    
public:
    ArrayQueue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }
    
    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }
    
    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }
    
    int peek() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    bool is_empty() { return size == 0; }
    bool is_full() { return size == capacity; }
    
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
    
    ~ArrayQueue() { delete[] arr; }
};

int main() {
    ArrayQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();  // 10 20 30
    
    cout << "Dequeued: " << queue.dequeue() << endl;  // 10
    cout << "Front: " << queue.peek() << endl;        // 20
    queue.display();  // 20 30
    return 0;
}