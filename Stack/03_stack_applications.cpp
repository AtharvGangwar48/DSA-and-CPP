// Stack Applications - Practical Examples
// Use Case: Expression evaluation, parentheses matching, postfix conversion

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check balanced parentheses
bool is_balanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
        }
    }
    return s.empty();
}

// Evaluate postfix expression
int evaluate_postfix(string expr) {
    stack<int> s;
    for (char c : expr) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

// Reverse string using stack
string reverse_string(string str) {
    stack<char> s;
    for (char c : str) s.push(c);
    
    string result = "";
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

int main() {
    cout << "Balanced: " << is_balanced("({[]})") << endl;     // 1
    cout << "Balanced: " << is_balanced("({[})") << endl;      // 0
    
    cout << "Postfix 231*+: " << evaluate_postfix("231*+") << endl;  // 5
    
    cout << "Reversed 'hello': " << reverse_string("hello") << endl;  // olleh
    return 0;
}