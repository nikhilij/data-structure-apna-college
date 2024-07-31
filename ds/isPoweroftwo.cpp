// write a program to check if a given number is power of 2
#include<iostream>
using namespace std;

bool isPowerOfTwo(int n){
    return(n && !(n & (n-1)));
}
int main(){
    int n;
    cin>>n;

    if(isPowerOfTwo(n)){
        cout<<"Yes";
    }else{
        cout<<"NO";
    }
}