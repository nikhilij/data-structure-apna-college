#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findsmallest(vector<int> arr){
    int smallest = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]<smallest){
            smallest = arr[i];
        }
    }
    return smallest;
}

int main(){

    vector<int> numbers = {2,5,1,3,0,4};
    int smallest = findsmallest(numbers);
    cout<<"The smallest number is: "<<smallest<<endl;
    return 0;
}