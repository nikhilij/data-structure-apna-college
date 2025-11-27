// Problem Statement: Given an array of n size, rotate the array by k elements using the Block Swap Algorithm.

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>a = {1,2,3,4,5,6,7};
    int n = a.size();
    int k = 3; // Number of elements to rotate

    k = k % n; // In case k is greater than n

    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());

    cout << "Rotated array: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}