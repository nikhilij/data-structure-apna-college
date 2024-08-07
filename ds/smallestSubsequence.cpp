#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct subsequence
{
    int length;
    int start;
    int end;

    subsequence(int l, int s, int e) : length(l), start(s), end(e) {}
};

vector<int> smallestSubsequenceWithSumK(const vector<int> &nums, int k)
{
    int n = nums.size(); // Size of the original array
    vector<int> result;

    // Lambda function for comparison in the priority queue
    auto compare = [](const subsequence &a, const subsequence &b)
    {
        return a.length > b.length;
    };

    // Priority queue (min heap) for subsequences
    priority_queue<subsequence, vector<subsequence>, decltype(compare)> minHeap(compare);

    int start = 0;
    int currentSum = 0;

    for (int end = 0; end < n; end++)
    {
        currentSum += nums[end];

        // While the current sum is greater than or equal to k
        while (currentSum >= k)
        {
            if (currentSum == k)
            {
                // Push the current subsequence details into the min heap
                minHeap.push(subsequence(end - start + 1, start, end));
            }
            // Shrink the window
            currentSum -= nums[start];
            start++;
        }
    }

    // Extract the smallest subsequence from the min heap
    if (!minHeap.empty())
    {
        subsequence smallest = minHeap.top();
        result = vector<int>(nums.begin() + smallest.start, nums.begin() + smallest.end + 1);
    }

    return result;
}

int main()
{
    // Example usage
    vector<int> nums = {1, 2, 3, 7, 5};
    int k = 12;
    vector<int> subsequence = smallestSubsequenceWithSumK(nums, k);

    if (!subsequence.empty())
    {
        cout << "Smallest subsequence with sum " << k << ": ";
        for (int num : subsequence)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << "Size of the result: " << subsequence.size() << endl;
    }
    else
    {
        cout << "No subsequence with sum " << k << " found." << endl;
    }

    return 0;
}
