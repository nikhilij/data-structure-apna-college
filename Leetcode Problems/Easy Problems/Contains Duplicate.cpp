#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int n : nums) {
            if (mp.find(n) == mp.end()) {
                mp[n]++;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    Solution sol;
    cout << (sol.containsDuplicate(nums) ? "true" : "false") << '\n';
    return 0;
}