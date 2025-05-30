// write the cpp program to find the longest consecutive subsequence of a given array

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int> &arr)
    {
        // Your code here
        unordered_set<int> seen(arr.begin(), arr.end());
        int resultlength = 0;

        for (int x : arr)
        {
            if (seen.find(x - 1) == seen.end())
            {
                int curr = x;
                int len = 1;
                while (seen.find(curr + 1) != seen.end())
                {
                    curr += 1;
                    len += 1;
                }
                resultlength = max(resultlength, len);
            }
        }
        return resultlength;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> arr1 = {100, 4, 200, 1, 3, 2};
    cout << "Array: ";
    for (int x : arr1)
        cout << x << " ";
    cout << "\nLongest consecutive subsequence length: " << sol.longestConsecutive(arr1) << endl;

    // Test case 2
    vector<int> arr2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "\nArray: ";
    for (int x : arr2)
        cout << x << " ";
    cout << "\nLongest consecutive subsequence length: " << sol.longestConsecutive(arr2) << endl;

    return 0;
}
