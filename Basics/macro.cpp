#include<iostream>
using namespace std;

#define PI 3.14159

int main() {
    int radius = 5;
    double area = PI * radius * radius;
    cout << "Value of PI: " << PI << endl;
    cout << "Area of circle with radius " << radius << " is: " << area << endl;
    return 0;
}