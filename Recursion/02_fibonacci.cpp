// Fibonacci Sequence
// Use Case: Financial modeling, nature patterns, algorithm analysis

#include <iostream>
#include <unordered_map>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Optimized with memoization
unordered_map<int, long long> memo;

long long fib_memo(int n) {
    if (memo.count(n)) return memo[n];
    if (n <= 1) return n;
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

int main() {
    cout << fibonacci(7) << endl;     // 13
    cout << fib_memo(50) << endl;     // 12586269025 (fast!)
    return 0;
}
