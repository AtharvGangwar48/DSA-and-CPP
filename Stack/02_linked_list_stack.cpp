// Stack Implementation using Linked List
// Use Case: Dynamic size, memory efficient, recursive algorithms

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* top;
    
public:
    LinkedListStack() : top(nullptr) {}
    
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    
    int pop() {
        if (!top) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    
    int peek() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    
    bool is_empty() { return top == nullptr; }
    
    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    ~LinkedListStack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    LinkedListStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();  // 30 20 10
    
    cout << "Popped: " << stack.pop() << endl;  // 30
    cout << "Top: " << stack.peek() << endl;    // 20
    stack.display();  // 20 10
    return 0;
}