#include<iostream>
using namespace std;

int main(){
    const int pi = 3.14;
    cout << 'Value of pi: ' << pi << endl;
    int radius;
    cout << "Enter radius of circle: ";
    cin >> radius;
    double area = pi * radius * radius;
    cout << "Area of circle: " << area << endl;
    return 0;
}