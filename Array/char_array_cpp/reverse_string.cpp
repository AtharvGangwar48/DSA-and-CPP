#include<iostream>
using namespace std;

void reverseString(char str[]) {
    int start = 0;
    int end = 0;

    while (str[end] != '\0') {
        end++;
    }
    end--; 

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    reverseString(str);

    cout << "Reversed string is: " << str << endl;
    return 0;
}