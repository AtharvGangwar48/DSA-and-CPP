#include<iostream>
using namespace std;

int main(){
    char arr[20];
    float brr[10];
    double crr[10];

    cout<<"Enter your name: ";
    cin>>arr;
    cout<<"The name is "<<arr<<endl;

    cout<<"Enter your float values: ";
    for(int i=0;i<3;i++){
        cin>>brr[i];
    }
    cout<<"The float values are: ";
    for(int i=0;i<3;i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;     

    cout<<"Enter your double values: "; 
    for(int i=0;i<3;i++){
        cin>>crr[i];
    }
    cout<<"The double values are: ";
    for(int i=0;i<3;i++){
        cout<<crr[i]<<" ";
    }
    cout<<endl;
    return 0;
}