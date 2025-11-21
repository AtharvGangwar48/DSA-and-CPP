#include<iostream>
using namespace std;

void fibonacci(int x) {
    int a = 0, b = 1; 
    for (int i = 0; i < x; i++) {
        cout << a << " ";  
        int next_num = a + b;  
        a = b;  
        b = next_num;  // 
    }
}

int main() {
    int n;
    cin >> n;
    fibonacci(n);  
    return 0;
}
