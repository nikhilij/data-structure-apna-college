// count frequency of elements in a given array using hashmap

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


int main(){
    int a[]={2,2,2,1,1,4,3,4};
    int n=sizeof(a)/sizeof(a[0]);
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(auto it:mp){
        cout<< it.first << " : "<<it.second << endl;
    }

    return 0;
}