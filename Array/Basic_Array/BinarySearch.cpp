#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int s=0,e=n-1,mid;
    bool found=false;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==target){
            found=true;
            cout<<mid<<endl;
            break;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    if(!found){
        cout<<"Element not found"<<endl;
    }
    return 0;
}