#include<stdio.h>
using namespace std;

int& getReferenceVariable(int &refVar) {
    // Return the reference variable
    return refVar;
}

int main() {
    int a = 10;
    // Get a reference to variable 'a'
    int &ref = getReferenceVariable(a);

    // Modify the value using the reference
    ref = 20;

    // Print the modified value of 'a'
    printf("Value of a after modification through reference: %d\n", a);
    return 0;
}