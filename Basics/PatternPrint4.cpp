#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    int row = 0; 
    int star=0;  
    while (row<n){
        for(int i=1;i<=n-row;i++){
            cout<<i<<" ";
        }
        star=row*2;
        for(int i=0;i<star;i++){
            cout<<"* ";
        }
        for(int i=n-row;i>0;i--){
            cout<<i<<" ";
        }
        row++;
        cout<<endl;
        star++;
    }
    return 0;
}
