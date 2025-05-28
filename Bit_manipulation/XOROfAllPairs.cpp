// write the cpp program to find the xor of all pairs of given array 

#include<iostream>
using namespace std;

int XorofAllPairs(int arr[],int n){
    int result = 0;
    cout<< "Pairs and their XORS:\n";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int pairXor = arr[i] ^ arr[j];
            cout << "{" << arr[i] << ", " << arr[j] << "} -> XOR = " << pairXor << endl;
            result ^= pairXor; // XOR of all pairs
        }
    }
    return result;
}


int main(){
    int arr [] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = XorofAllPairs(arr, n);
    cout << "XOR of all pairs = " << result << endl;
    return 0;
}