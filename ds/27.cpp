// wap to check whether the array is sorted or not 
// use recursion

#include<iostream>

using namespace std;

int check(int a[],int n){

    if(n==1){
        return 1;
    }
    
    int restarray=check(a+1,n-1);
    return (a[0]<a[1] && restarray);    
}

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(check(a,n)){
        cout<<"true";
    }
    else{
        cout<<"no";
    }
    return 0;
}