// write the cpp code for the generating the permutation of given collection of numbers in which duplicates are allowed
#include <vector>
#include <unordered_map>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }
        // sort(nums.begin(),nums.end());
        // Start the recursion
        dfs(nums, mp, curr, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, map<int, int>& mp, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (auto& [n, count] : mp) {
            if (count > 0) {
                curr.push_back(n);
                mp[n]--;
                dfs(nums, mp, curr, res);  // Recursive call
                mp[n]++;
                curr.pop_back();
            }
        }
    }
};
#include <iostream>

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = solution.permuteUnique(nums);

    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


