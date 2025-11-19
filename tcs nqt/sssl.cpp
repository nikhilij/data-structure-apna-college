// second smallest and second largest number in an array
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findSecondSmallestAndLargest(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }

    int firstSmallest = INT_MAX, secondSmallest = INT_MAX;
    int firstLargest = INT_MIN, secondLargest = INT_MIN;

    for (int num : arr) {
        // Update smallest and second smallest
        if (num < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = num;
        } else if (num < secondSmallest && num != firstSmallest) {
            secondSmallest = num;
        }

        // Update largest and second largest
        if (num > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = num;
        } else if (num > secondLargest && num != firstLargest) {
            secondLargest = num;
        }
    }

    if (secondSmallest == INT_MAX || secondLargest == INT_MIN) {
        throw invalid_argument("Array must contain at least two distinct elements.");
    }

    return {secondSmallest, secondLargest};
}

int main() {
    vector<int> numbers = {2, 5, 1, 3, 0, 4};
    try {
        auto [secondSmallest, secondLargest] = findSecondSmallestAndLargest(numbers);
        cout << "The second smallest number is: " << secondSmallest << endl;
        cout << "The second largest number is: " << secondLargest << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}