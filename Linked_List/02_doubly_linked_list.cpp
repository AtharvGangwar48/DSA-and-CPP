// Doubly Linked List Implementation
// Use Case: Browser history, text editors, LRU cache

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void insert_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void insert_back(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void delete_val(int val) {
        Node* temp = head;
        while (temp && temp->data != val)
            temp = temp->next;
        
        if (!temp) return;
        
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        
        if (temp->next) temp->next->prev = temp->prev;
        else tail = temp->prev;
        
        delete temp;
    }
    
    void display_forward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void display_backward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insert_front(10);
    list.insert_back(20);
    list.insert_front(5);
    
    list.display_forward();   // 5 <-> 10 <-> 20 <-> NULL
    list.display_backward();  // 20 <-> 10 <-> 5 <-> NULL
    
    list.delete_val(10);
    list.display_forward();   // 5 <-> 20 <-> NULL
    return 0;
}