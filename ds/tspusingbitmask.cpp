// write the cpp program to find the miniumum cost for exploring all the cities
// from the source city 0 and return to the soruce city 0 use bitmasking to
// optimze the solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tsp(vector<vector<int>>& cost)
    {
        int n = cost.size();
        int allsubsets = (1 << n) - 1;

        vector<vector<long long>> dp(allsubsets + 1, vector<long long>(n, LLONG_MAX / 2));

        if (n == 1) {
            return cost[0][0];
        }

        dp[1][0] = 0;

        for (int mask = 1; mask <= allsubsets; mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i) != 0) {
                    int prevmask = mask ^ (1 << i);
                    for (int j = 0; j < n; j++) {
                        if (mask & (1 << j) != 0) {
                            if (dp[prevmask][j] < LLONG_MAX / 2) {
                                long long newcost = dp[prevmask][j] + cost[j][i];
                                dp[mask][i] = min(dp[mask][i], newcost);
                            }
                        }
                    }
                }
            }
        }

        long long mintourcost = LLONG_MAX / 2;
        for (int i = 1; i < n; i++) {
            if (dp[allsubsets][i] < LLONG_MAX / 2) {
                long long curr = dp[allsubsets][i] + cost[i][0];
                mintourcost = min(mintourcost, curr);
            }
        }
        return mintourcost;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    cout << s.tsp(cost) << endl;
    return 0;
}
