// Stack Implementation using Array
// Use Case: Function calls, expression evaluation, undo operations

#include <iostream>
using namespace std;

class ArrayStack {
private:
    int* arr;
    int top;
    int capacity;
    
public:
    ArrayStack(int size) : capacity(size), top(-1) {
        arr = new int[capacity];
    }
    
    void push(int val) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = val;
    }
    
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
    
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    
    bool is_empty() { return top == -1; }
    bool is_full() { return top == capacity - 1; }
    
    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
    
    ~ArrayStack() { delete[] arr; }
};

int main() {
    ArrayStack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();  // 30 20 10
    
    cout << "Popped: " << stack.pop() << endl;  // 30
    cout << "Top: " << stack.peek() << endl;    // 20
    stack.display();  // 20 10
    return 0;
}