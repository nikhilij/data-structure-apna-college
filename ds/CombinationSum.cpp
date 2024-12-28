#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        function<void(int, int)> dfs = [&](int i, int total) {
            if (total == target) {
                res.push_back(curr);
                return;
            }
            if (i >= candidates.size() || total > target) {
                return;
            }

            // Include the current candidate
            curr.push_back(candidates[i]);
            dfs(i, total + candidates[i]);
            curr.pop_back();

            // Exclude the current candidate and move to the next
            dfs(i + 1, total);
        };

        dfs(0, 0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    for (const auto &combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}