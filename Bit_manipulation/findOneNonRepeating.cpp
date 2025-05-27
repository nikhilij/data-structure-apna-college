// Find the single non-repeating element

// In an array where every other element appears twice except one.

#include <iostream>
using namespace std;

int findNonRepeating(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The non-repeating element is: " << findNonRepeating(arr, n) << endl;
    return 0;
} 