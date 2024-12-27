// find the length of longest increasing subsequences

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),1);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    lis[i]=max(lis[i],1+lis[j]);
                }
            }
        }
        return *max_element(lis.begin(),lis.end());
    }

    //better optimal solution in O(nlogn)

    int leng(vector<int>& nums){
        vector<int> sub;
        for(int n:nums){
            auto it = lower_bound(sub.begin(),sub.end(),n);
            if(it==sub.end()){
                sub.push_back(n);
            }else{
                *it=n;
            }
        }
        return sub.size();
    }
};
int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}