#include<iostream>
#include<string>
using namespace std;

//using string library in C++
int main(){
    string str1 = "Hello, ";
    string str2 = "World!";
    
    // Concatenation
    string str3 = str1 + str2;
    cout << "Concatenated String: " << str3 << endl;

    // Length of the string
    cout << "Length of str3: " << str3.length() << endl;

    // Accessing characters
    cout << "First character of str3: " << str3[0] << endl;

    // Substring
    string subStr = str3.substr(7, 5); // "World"
    cout << "Substring of str3: " << subStr << endl;

    // Finding a substring
    size_t pos = str3.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    } else {
        cout << "'World' not found" << endl;
    }

    return 0;
}