// wap to Three sum problem using cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ThreeSumProblem(vector<int> &nums, int t)
{

    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {

            int sum = nums[left] + nums[right] + nums[i];
            if (sum == t)
            {
                result.push_back({nums[i],nums[left],nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < t)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {12, 3, 7, 1, 6, 9};
    int t = 24;
    vector<vector<int>> result = ThreeSumProblem(nums, t);

    for (const auto &triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

}