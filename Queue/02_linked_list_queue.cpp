// Queue Implementation using Linked List
// Use Case: Dynamic size, print job management, task scheduling

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;
    
public:
    LinkedListQueue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    int dequeue() {
        if (!front) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return val;
    }
    
    int peek() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }
    
    bool is_empty() { return front == nullptr; }
    
    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    ~LinkedListQueue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    LinkedListQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();  // 10 20 30
    
    cout << "Dequeued: " << queue.dequeue() << endl;  // 10
    cout << "Front: " << queue.peek() << endl;        // 20
    queue.display();  // 20 30
    return 0;
}