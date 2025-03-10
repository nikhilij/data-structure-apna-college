// write the program to sort the given array containing repeated elements by frequency 

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {2, 5, 2, 8, 5, 6, 8, 8};
    int n = a.size();
    unordered_map<int,int> freq;
    unordered_map<int,int> first_occur;

    for(int i=0;i<n;i++){
        freq[a[i]]++;
        if(first_occur.find(a[i])==first_occur.end()){
            first_occur[a[i]]=i;
        }
    }

    // sort 
    sort(a.begin(),a.end(),[&](int a , int b){
        //lets first sort them in decreasing frequency order
        if(freq[a]!=freq[b]) return freq[a]>freq[b];

        // if there frequencies are same then sort them by first occurence

        return first_occur[a]<first_occur[b];
    });

    // let me print the array 

    for(auto it : a){
        cout<<it<<" ";
    }
    return 0;
}