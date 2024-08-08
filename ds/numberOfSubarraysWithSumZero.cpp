#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarraysWithSumK(const vector<int> &arr, int k) {
    unordered_map<int, int> prefixSumFreq;
    int count = 0;
    int currentSum = 0;

    // Initialize the map with a zero sum frequency of 1
    prefixSumFreq[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        // If currentSum - k has been seen before, it means there are subarrays with sum k
        if (prefixSumFreq.find(currentSum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[currentSum - k];
        }

        // Increment the frequency of currentSum in the map
        prefixSumFreq[currentSum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {3, 4, 7, 2, -3, 1, 4, 2};
    int k = 7;
    int result = countSubarraysWithSumK(arr, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}
