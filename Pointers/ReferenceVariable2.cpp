#include<iostream>
using namespace std;

int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}

void updateValue(int &n){
    n = n + 10;
}   

void updateValue2(int n){
    n = n + 10;
}

int main(){
    func(5); // Warning: returning reference to local variable
    int value = 20;
    cout << "Original value: " << value << endl;    
    updateValue(value);
    cout << "Value after updateValue (by reference): " << value << endl;
    updateValue2(value);
    cout << "Value after updateValue2 (by value): " << value << endl;
    return 0;
}