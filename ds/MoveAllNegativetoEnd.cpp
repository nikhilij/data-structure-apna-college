// write the cpp program to move all the negative elements to the end while maintaing the order of positive elements.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveNegative(vector<int>& arr){
    int n = arr.size();
    vector<int>temp(n);
    int j = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            temp[j] = arr[i];
            j++;
        }
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            temp[j] = arr[i];
            j++;
        }
    }

    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}

int main(){
   vector<int>arr={1,-2,3,-4,5,-6,7,-8,9};
    moveNegative(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}