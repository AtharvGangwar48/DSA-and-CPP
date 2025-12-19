// Double Ended Queue (Deque) Implementation
// Use Case: Sliding window problems, palindrome checking, undo/redo operations

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;
    
public:
    Deque() : front(nullptr), rear(nullptr) {}
    
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }
    
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }
    
    int pop_front() {
        if (!front) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
        return val;
    }
    
    int pop_back() {
        if (!rear) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int val = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
        return val;
    }
    
    int peek_front() {
        return front ? front->data : -1;
    }
    
    int peek_back() {
        return rear ? rear->data : -1;
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
};

int main() {
    Deque dq;
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);
    dq.display();  // 5 10 20
    
    cout << "Pop front: " << dq.pop_front() << endl;  // 5
    cout << "Pop back: " << dq.pop_back() << endl;    // 20
    dq.display();  // 10
    return 0;
}