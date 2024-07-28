// wap for a problem below
// for a given array and integers k and x find the maximum sum subarray of size k and having sum less than k

#include<iostream>
using namespace std;

int findMaxSumSubarray(int a[],int n,int k,int x){
    int ans=0;
    int sum=0;

    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    
    if(sum<x){
        ans=sum;
    }

    for(int i=k;i<n;i++){
        sum=sum-a[i-k];
        sum+=a[i];
        if(sum<x){
            ans=max(ans,sum);
        }
    }
    return ans;
}

int main()
{
    int a[]={7,5,4,6,8,9};
    int k=3,x=20;
    cout<<findMaxSumSubarray(a,6,k,x);
}