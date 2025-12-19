// Doubly Circular Linked List Implementation
// Use Case: Advanced navigation systems, complex undo/redo operations

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList {
private:
    Node* head;
    
public:
    DoublyCircularLinkedList() : head(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = newNode->prev = newNode;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
        }
    }
    
    void delete_val(int val) {
        if (!head) return;
        
        Node* temp = head;
        do {
            if (temp->data == val) {
                if (temp->next == temp) {
                    delete temp;
                    head = nullptr;
                    return;
                }
                
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                
                if (temp == head) head = temp->next;
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    
    void display_forward() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(circular)" << endl;
    }
    
    void display_backward() {
        if (!head) return;
        Node* temp = head->prev;
        do {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << "(circular)" << endl;
    }
};

int main() {
    DoublyCircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    
    list.display_forward();   // 10 <-> 20 <-> 30 <-> (circular)
    list.display_backward();  // 30 <-> 20 <-> 10 <-> (circular)
    
    list.delete_val(20);
    list.display_forward();   // 10 <-> 30 <-> (circular)
    return 0;
}