#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>cols;

    while(rows--){
        int c = cols;
        while(c--){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}