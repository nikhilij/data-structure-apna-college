#include<bits/stdc++.h>
using namespace std;

bool pairsum(int a[],int n,int k){
    // this is the brute approach
    // //k is the target sum
    // for(int i =0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         if(a[i]+a[j]==k){
    //             cout<<i<<" "<<j;
    //             return true;
    //         }
    //     }
    // }
    // return false;


    // now optimial
    int left=0;
    int right=n-1;
    while(left<right){
        if(a[left]+a[right]==k){
            cout<< left<<"  "<< right<<endl;
            return true;
        }
        else if(a[left]+a[right]>k){
            right--;
        }
        else{
            left++;
        }
    }
    return false;
}

int main(){
    // input number of elements
    int n;
    cin>>n;

    int a[n];
    //input array
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //input tsum
    int tsum;
    cin>>tsum;
    if(pairsum(a,n,tsum)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}