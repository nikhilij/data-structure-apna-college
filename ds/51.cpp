// wap to number formed from subarray of size k, divisible by 3

// for a given array and an integer k, check if any subarray of size k exists in the array such that elements in the subarray form a number divisible by 3

// example 8,23,45,12,56,4 
// 12564 is divisble by 3 so this is out answer

#include<iostream>
#include<string>
using namespace std;

bool check(int a[],int n,int k){

    for(int i=0;i<=n-k;i++){
        string s="";
        for(int j=i;j<i+k;j++){
            s+=to_string(a[j]);
        }
        int num=stoi(s);
        if(num%3==0){
            return true;
        }
    }

    return false;
}



int main(){
    int a[]={8,23,45,12,56,4};

    cout<<check(a,6,3);
    
}
