// write the cpp program to arrange the given array such that the first half in increasing order and other half in decreasing order.
#include <bits/stdc++.h>
using namespace std;

// Class to hold the rearrangement solution
class Solution {
public:
    // Function to rearrange first half ascending and second half descending
    void rearrangeArray(vector<int>& arr) {
        // Sort the entire array
        sort(arr.begin(), arr.end());

        int n = arr.size();
        // Reverse the second half
        reverse(arr.begin() + n / 2, arr.end());
    }
};

// Driver code
int main() {
    vector<int> arr = {5, 2, 9, 1, 6, 3};

    Solution sol;
    sol.rearrangeArray(arr);

    // Print rearranged array
    for (int x : arr) cout << x << " ";
}