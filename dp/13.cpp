#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
        }
        while (k != minHeap.size())
        {
            minHeap.pop();
        }
    }

    int add(int val)
    {
        int x = minHeap.top();
        minHeap.pop();
        minHeap.push(val);
        return x;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */