// Factorial - Classic Recursion Example
// Use Case: Calculate n! = n × (n-1) × ... × 1

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5) << endl;  // 120
    cout << factorial(0) << endl;  // 1
    return 0;
}
