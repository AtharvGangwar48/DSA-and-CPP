#include<iostream>
using namespace std;

int main(){
    int a=10;
    float b=5.5;
    char c='A';
    bool d=true;
    double e=3.14159;

    cout<<"Integer: "<<a<<endl;
    cout<<"Float: "<<b<<endl;
    cout<<"Character: "<<c<<endl;
    cout<<"Boolean: "<<d<<endl;
    cout<<"Double: "<<e<<endl;

    int sizeInt = sizeof(a);
    int sizeFloat = sizeof(b);
    int sizeChar = sizeof(c);         

    cout<<"Size of Integer: "<<sizeInt<<" bytes"<<endl; 
    cout<<"Size of Float: "<<sizeFloat<<" bytes"<<endl;
    cout<<"Size of Character: "<<sizeChar<<" bytes"<<endl;

    return 0;
}