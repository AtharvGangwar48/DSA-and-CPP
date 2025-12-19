// Circular Linked List Implementation
// Use Case: Round-robin scheduling, multiplayer games, circular buffers

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* last;
    
public:
    CircularLinkedList() : last(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            last = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
    
    void delete_val(int val) {
        if (!last) return;
        
        Node* curr = last->next;
        Node* prev = last;
        
        do {
            if (curr->data == val) {
                if (curr == last && curr->next == curr) {
                    delete curr;
                    last = nullptr;
                    return;
                }
                
                prev->next = curr->next;
                if (curr == last) last = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
    }
    
    void display() {
        if (!last) return;
        Node* temp = last->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to start)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();  // 10 -> 20 -> 30 -> (back to start)
    
    list.delete_val(20);
    list.display();  // 10 -> 30 -> (back to start)
    return 0;
}