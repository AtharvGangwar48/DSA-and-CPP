#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a decimal number: ";
    cin>>n;
    while(n!=0){
        int bit = n&1;
        cout<<bit;
        n = n>>1;
    }
    cout<<endl;
    string binaryString; 
    cout << "Enter a binary number: ";
    cin >> binaryString;

    int decimalValue = 0;
    int powerOfTwo = 1; 

    for (int i = binaryString.length() - 1; i >= 0; --i) {
        if (binaryString[i] == '1') {
            decimalValue += powerOfTwo;
        }
        powerOfTwo *= 2; 
    }

    cout << "Decimal equivalent: " << decimalValue << endl;

    return 0;
}