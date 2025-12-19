#include<iostream>
#include<memory>
using namespace std;

class Student {
public:
    string name;
    int age;
    
    Student(string n, int a) : name(n), age(a) {
        cout << "Student " << name << " created" << endl;
    }
    
    ~Student() {
        cout << "Student " << name << " destroyed" << endl;
    }
    
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

void rawPointerExample() {
    cout << "=== Raw Pointer Example ===" << endl;
    Student *student = new Student("Alice", 20);
    student->display();
    delete student; // Manual cleanup required
}

void uniquePtrExample() {
    cout << "\n=== Unique Pointer Example ===" << endl;
    unique_ptr<Student> student = make_unique<Student>("Bob", 21);
    student->display();
    // Automatic cleanup when student goes out of scope
}

void sharedPtrExample() {
    cout << "\n=== Shared Pointer Example ===" << endl;
    shared_ptr<Student> student1 = make_shared<Student>("Charlie", 22);
    
    {
        shared_ptr<Student> student2 = student1; // Shared ownership
        cout << "Reference count: " << student1.use_count() << endl;
        student2->display();
    } // student2 goes out of scope, but object still exists
    
    cout << "Reference count after scope: " << student1.use_count() << endl;
    student1->display();
    // Object destroyed when last shared_ptr goes out of scope
}

void dynamicArrayWithSmartPointers() {
    cout << "\n=== Dynamic Array with Smart Pointers ===" << endl;
    
    // unique_ptr for array
    unique_ptr<int[]> arr = make_unique<int[]>(5);
    
    for(int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    
    cout << "Array elements: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Automatic cleanup
}

int main(){
    rawPointerExample();
    uniquePtrExample();
    sharedPtrExample();
    dynamicArrayWithSmartPointers();
    
    return 0;
}