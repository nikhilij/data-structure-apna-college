// write a program to count number of ones in binary representation of a number

#include<iostream>

using namespace std;

int count(int n){
    int c=0;
    while(n){
        n=n&(n-1);
        c++;
    }
    return c;
}

int main(){

    int n;
    cin>>n;

    cout<<count(n);
    
    return 0;
}