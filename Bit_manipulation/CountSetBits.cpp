// write the cpp program to count the number of set bits in an integer
// they will ask you the tc of this as question bigO of n and space O(1)

#include<iostream>
using namespace std;

int main(){
    int n = 13;
    int count  = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    cout<<"Number of set bits: " << count << endl;
    return 0;
}