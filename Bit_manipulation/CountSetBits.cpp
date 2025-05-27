// write the cpp program to count the number of set bits in an integer
// they will ask you the tc of this as question bigO of n and space O(1)


#include<iostream>
using namespace std;


int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Clear the least significant bit set
        count++;
    }
    return count;
}

int countNumberOfbitsToFlip(int a,int b){
    int xorResult = a ^ b; // XOR to find differing bits
    return countSetBits(xorResult); // Count the set bits in the XOR result
}


int main(){
    int a = 13, b = 7;
    cout << "Number of bits to flip: " << countNumberOfbitsToFlip(a, b) << endl;
    return 0;
}