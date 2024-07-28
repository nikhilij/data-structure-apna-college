// wap to check whether subarray exist whose digits formed are divisble by k 

#include<iostream>
using namespace std;

bool check(int a[],int n,int k){
    if(k>n) return false; // if k is greater than the array size 

    int sum=0; // initialize sum to 0

    //finding the first k sum 
    for(int i=0;i<k;i++){
        sum+=a[i];
    }

    //if sum is divisible by 3 then return true
    if(sum%k==0){
        return true;
    }

    // if sum is not divisible by 3 then 
    // remove the first element and add the next element and check whether the sum is divisible by 3 or not  
    for(int i=k;i<n;i++){
        sum+=a[i]-a[i-k];
        if(sum%k==0) return true;
    }
    return false;
}

int main(){
    int a[]={4, 5, 6, 7, 8, 9};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    if(check(a,n,k)){
        cout<<"yes";
    }
    else{
        cout<<"No";
    }
}