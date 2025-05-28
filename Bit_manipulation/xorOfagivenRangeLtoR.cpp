// write the cpp program to get the xor of numbers in a given range L to R
#include <iostream>
using namespace std;

// Get XOR from 1 to n using pattern
// this is the pattern that it follows when finding xor of 1 to n elements
int xor1toN(int n) {
    if (n % 4 == 0) return n;  // if a numbers is divisible by 4 the xor value is n
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

/* the core concept is that :

XOR(1 to R) = 1 ^ 2 ^ 3 ^ ... ^ (L-1) ^ L ^ ... ^ R  
XOR(1 to L-1) = 1 ^ 2 ^ 3 ^ ... ^ (L-1)

(1 ^ 2 ^ ... ^ (L-1)) ^ (1 ^ 2 ^ ... ^ (L-1)) = 0

*/

// XOR from L to R
int xorLtoR(int L, int R) {
    return xor1toN(R) ^ xor1toN(L - 1);
}

int main() {
    int L = 3, R = 6;
    cout << "XOR from " << L << " to " << R << " = " << xorLtoR(L, R) << endl;
    return 0;
}
