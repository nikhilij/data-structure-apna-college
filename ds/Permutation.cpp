// write the cpp program to generate all the permutation of the given array of numbers

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void backTrack(vector<int>& nums, vector<vector<int>>& res,
                   vector<bool>& used, vector<int> path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backTrack(nums, res, used, path);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backTrack(nums, res, used, path);
        return res;
    }
};
    
int main(){
    Solution s;
    vector<int> nums = {1, 2, 3}; 
    vector<vector<int>> result = s.permute(nums);

    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
}