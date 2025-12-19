#include<iostream>
using namespace std;

void pointerInfo(void *ptr, char type){
    switch(type){
        case 'i': {
            int *intPtr = static_cast<int*>(ptr);
            cout << "Integer value: " << *intPtr << endl;
            break;
        }
        case 'f': {
            float *floatPtr = static_cast<float*>(ptr);
            cout << "Float value: " << *floatPtr << endl;
            break;
        }
        case 'c': {
            char *charPtr = static_cast<char*>(ptr);
            cout << "Character value: " << *charPtr << endl;
            break;
        }
        default:
            cout << "Unknown type" << endl;
    }
}

int main(){
    int intValue = 42;
    float floatValue = 3.14f;
    char charValue = 'A';

    void *ptr;

    ptr = &intValue;
    pointerInfo(ptr, 'i');

    ptr = &floatValue;
    pointerInfo(ptr, 'f');

    ptr = &charValue;
    pointerInfo(ptr, 'c');

    return 0;
}