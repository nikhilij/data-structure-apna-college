// wap to write the cpp program to find the median of two sorted arrays by merging them 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();
        int low = 0;
        int high = n; // Set high to n for binary search

        double median = 0.0;

        while (low <= high)
        {
            int i = low + (high - low) / 2; // Partition index for nums1
            int j = (m + n) / 2 - i;        // Partition index for nums2

            // Edge cases for maxLeft and minRight
            int maxLeftA = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightA = (i == n) ? INT_MAX : nums1[i];
            int maxLeftB = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightB = (j == m) ? INT_MAX : nums2[j];

            // Check if we have found the correct partition
            if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            {
                // Found the correct partition
                if ((m + n) % 2 == 0)
                {
                    // Even case: median is the average of the two middle values
                    median = (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                }
                else
                {
                    // Odd case: median is the max of the left partition
                    median = max(maxLeftA, maxLeftB);
                }
                return median; // Return the computed median
            }
            else if (maxLeftA > minRightB)
            {
                // Move left in nums1
                high = i - 1;
            }
            else
            {
                // Move right in nums1
                low = i + 1;
            }
        }

        return median; // Should not reach here
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median of [1, 3] and [2]: " << median << endl; // Expected output: 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median of [1, 2] and [3, 4]: " << median << endl; // Expected output: 2.5

    nums1 = {0, 0};
    nums2 = {0, 0};
    median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median of [0, 0] and [0, 0]: " << median << endl; // Expected output: 0.0

    nums1 = {};
    nums2 = {1};
    median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median of [] and [1]: " << median << endl; // Expected output: 1.0

    nums1 = {2};
    nums2 = {};
    median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median of [2] and []: " << median << endl; // Expected output: 2.0

    return 0;
}
