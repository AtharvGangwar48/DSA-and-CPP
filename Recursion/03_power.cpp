// Power Function - Efficient Recursion
// Use Case: Fast exponentiation in cryptography, large number calculations

#include <iostream>
using namespace std;

long long power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    
    long long half = power(base, exp / 2);
    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main() {
    cout << power(2, 10) << endl;  // 1024
    cout << power(5, 3) << endl;   // 125
    return 0;
}
