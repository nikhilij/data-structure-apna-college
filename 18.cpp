// write a program to find the unique number from a given array
// using bit manipulation

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int xor_n=0;
    for(int i=0;i<n;i++){
        xor_n^=a[i];
    }
    cout<<xor_n;
    return 0;
}