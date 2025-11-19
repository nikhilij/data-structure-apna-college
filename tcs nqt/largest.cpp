#include<bits/stdc++.h>
using namespace std;   
int findlargest(vector<int> arr){
    int largest = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){

    vector<int> numbers = {2,5,1,3,0,4};
    int largest = findlargest(numbers);
    cout<<"The largest number is: "<<largest<<endl;
    return 0;
}