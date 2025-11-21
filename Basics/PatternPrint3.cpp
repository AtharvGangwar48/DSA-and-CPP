#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    int rows = 1;   
    while (rows<=n)
    {
        int cols = 1;
        char start = 'A' + rows - 1; 
        while (cols<=rows)
        {
            cout<<start<<" ";
            start++;
            cols++;
        }
        cout<<endl;
        rows++;
    }
    return 0;
}
