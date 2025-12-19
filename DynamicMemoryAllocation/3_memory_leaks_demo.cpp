#include<iostream>
using namespace std;

void memoryLeakExample(){
    // BAD: Memory leak - allocated but never deleted
    int *ptr = new int(100);
    cout << "Allocated memory with value: " << *ptr << endl;
    // Missing delete ptr; - This causes memory leak!
}

void correctMemoryManagement(){
    // GOOD: Proper memory management
    int *ptr = new int(200);
    cout << "Allocated memory with value: " << *ptr << endl;
    delete ptr; // Properly deallocated
    ptr = nullptr; // Good practice to avoid dangling pointer
}

void danglingPointerExample(){
    int *ptr = new int(300);
    cout << "Value before delete: " << *ptr << endl;
    
    delete ptr;
    // ptr is now a dangling pointer
    
    // BAD: Accessing deleted memory (undefined behavior)
    // cout << *ptr << endl; // Don't do this!
    
    // GOOD: Set to nullptr after delete
    ptr = nullptr;
    
    if(ptr != nullptr){
        cout << "Safe to use ptr" << endl;
    } else {
        cout << "ptr is null, cannot access" << endl;
    }
}

int main(){
    cout << "=== Memory Leak Example ===" << endl;
    memoryLeakExample();
    
    cout << "\n=== Correct Memory Management ===" << endl;
    correctMemoryManagement();
    
    cout << "\n=== Dangling Pointer Example ===" << endl;
    danglingPointerExample();
    
    return 0;
}