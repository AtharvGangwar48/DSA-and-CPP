#include<iostream>
using namespace std;

int main(){
    int a=4, b=8;
    cout<<"a & b = "<<(a & b)<<endl;  // Bitwise AND
    cout<<"a | b = "<<(a | b)<<endl;  // Bitwise OR
    cout<<"a ^ b = "<<(a ^ b)<<endl;  // Bitwise XOR
    cout<<"~a = "<<(~a)<<endl;        // Bitwise NOT
    cout<<"b << 1 = "<<(b << 1)<<endl; // Left Shift
    cout<<"b >> 1 = "<<(b >> 1)<<endl; // Right Shift
    return 0;
}