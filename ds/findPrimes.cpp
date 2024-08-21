// wap to find all the primes using eratosthenes algorithm 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Initialize array to 0
    int a[n+1] = {0}; // Ensure the array size is n+1 to handle index n

    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= n; i++) {
        if (a[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                a[j] = 1; // Mark as composite
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            cout << i << " ";
        }
    }

    return 0;
}
