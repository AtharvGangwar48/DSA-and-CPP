// Circular Queue Implementation
// Use Case: Buffer management, CPU scheduling, memory management

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, capacity;
    
public:
    CircularQueue(int cap) : capacity(cap + 1), front(0), rear(0) {
        arr = new int[capacity];
    }
    
    void enqueue(int val) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[rear] = val;
        rear = (rear + 1) % capacity;
    }
    
    int dequeue() {
        if (front == rear) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        return val;
    }
    
    int peek() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    bool is_empty() { return front == rear; }
    bool is_full() { return (rear + 1) % capacity == front; }
    
    void display() {
        if (front == rear) return;
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != rear);
        cout << endl;
    }
    
    ~CircularQueue() { delete[] arr; }
};

int main() {
    CircularQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();  // 10 20 30
    
    cout << "Dequeued: " << queue.dequeue() << endl;  // 10
    queue.enqueue(40);
    queue.display();  // 20 30 40
    return 0;
}