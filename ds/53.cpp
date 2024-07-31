#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

// Function to find the starting index of a palindromic subarray of size k
int findPalindrome(int a[], int n, int k) {
    if (k > n) {
        return -1; // If k is greater than the array size, no such subarray can exist
    }

    // Check each subarray of size k
    for (int i = 0; i <= n - k; ++i) {
        string concatenated = "";
        for (int j = i; j < i + k; ++j) {
            concatenated += to_string(a[j]);
        }
        if (isPalindrome(concatenated)) {
            return i; // Return the starting index of the palindromic subarray
        }
    }

    return -1; // No palindromic subarray found
}

int main() {
    int a[] = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int n = sizeof(a) / sizeof(a[0]);
    int ans = findPalindrome(a, n, k);

    if (ans == -1) {
        cout << "No";
    } else {
        cout << "Yes, starting at index " << ans;
    }

    return 0;
}
