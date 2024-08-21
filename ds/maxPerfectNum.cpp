// wap to find the maximum sum of k consecutive elements in an array where the elements have been transformed based on whether they are perfect numbers.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isNumberPerfect(int n) {
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i) {
                sum += i;
            } else {
                sum += i + n / i;
            }
        }
    }
    return sum == n && n != 1;
}

int maxSum(const vector<int>& nums, int k) {
    if (nums.size() < k) {
        return -1;
    }
    
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += nums[i];
    }
    
    int sum = res;
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i] - nums[i - k];
        res = max(res, sum);
    }
    
    return res;
}

int maxPerfectSum(vector<int> nums, int k) {
    for (int i = 0; i < nums.size(); i++) {
        if (isNumberPerfect(nums[i])) {
            nums[i] = 1;
        } else {
            nums[i] = 0;
        }
    }
    return maxSum(nums, k);
}

int main() {
    vector<int> nums = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;
    
    cout << maxPerfectSum(nums, k);
    
    return 0;
}
