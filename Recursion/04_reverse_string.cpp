// Reverse String using Recursion
// Use Case: String manipulation, palindrome checking

#include <iostream>
#include <string>
using namespace std;

string reverse_string(string s) {
    if (s.length() <= 1) return s;
    return s[s.length() - 1] + reverse_string(s.substr(0, s.length() - 1));
}

// Alternative approach
void reverse_helper(string& s, int left, int right) {
    if (left >= right) return;
    swap(s[left], s[right]);
    reverse_helper(s, left + 1, right - 1);
}

int main() {
    cout << reverse_string("hello") << endl;      // "olleh"
    cout << reverse_string("recursion") << endl;  // "noisrucer"
    
    string str = "world";
    reverse_helper(str, 0, str.length() - 1);
    cout << str << endl;  // "dlrow"
    return 0;
}
