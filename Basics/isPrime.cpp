#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    if(n==1){
        cout<<"1 is neither prime nor composite";
    }
    if(n==2){
        cout<<"2 is a prime number";
    }
    else{
        for(int i=2;i<n;i++){
            if(n%i==0){
                cout<<n<<" is a composite number";
                break;  
            }
            else{
                cout<<n<<" is a prime number";
                break;}
        }
    }
    return 0;
}