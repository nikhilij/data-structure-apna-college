// write the cpp program for the leetcode problem 456 132 Pattern problem
#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;
class Solution
{
public:
    bool find132pattern(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;

        std::stack<int> st;
        int curr_min = INT_MIN;

        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] < curr_min)
            {
                return true;
            }
            while (!st.empty() && nums[i] > st.top())
            {
                curr_min = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {-1, 3, 2, 0};
    s.find132pattern(arr) ? cout << "True" : cout << "False";
    return 0;
}