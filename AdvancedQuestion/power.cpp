//Time Complexity: O(log n)
#include <iostream>
using namespace std;

int power(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) { // If exponent is odd
            result *= base;
        }
        base *= base; // Square the base
        exponent /= 2; // Divide exponent by 2
    }
    return result;
}

int main() {
    int base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;

    int result = power(base, exponent);
    cout << base << " raised to the power of " << exponent << " is " << result << endl;

    return 0;
}