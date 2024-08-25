// wap to find the size of the longest subarray for consecutive absolute differnce is between [0 and 1]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pickingNumbers(const vector<int>& a) {
    // Find the maximum element in the array
    int max_val = *max_element(a.begin(), a.end());
    
    // Initialize frequency vector with size of max_val + 1
    vector<int> freq(max_val + 1, 0);
    
    // Count the frequency of each element
    for (int number : a) {
        freq[number]++;
    }
    
    int max_length = 0;
    
    // Calculate the maximum length of the subarray
    for (int i = 0; i < max_val; ++i) {
        max_length = max(max_length, freq[i] + freq[i + 1]);
    }
    
    // Also consider the case where the maximum element is the only element
    max_length = max(max_length, freq[max_val]);
    
    return max_length;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << pickingNumbers(a) << endl;
    
    return 0;
}
