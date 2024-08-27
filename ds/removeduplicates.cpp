// wap to remove duplicates
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = 1;

        while (left < n - 1 && right < n)
        {

            if (nums[left] == nums[right])
            {
                right++;
            }
            else
            {
                nums[++left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution s;
    int k = s.removeDuplicates(a);

    cout << k;
    return 0;
}
