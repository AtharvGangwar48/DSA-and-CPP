#include <iostream>
using namespace std;

inline double square(double x) {
    return x * x;
}

int main() {
    double num = 5.0;
    cout << "Square of " << num << " is: " << square(num) << endl;
    return 0;
}