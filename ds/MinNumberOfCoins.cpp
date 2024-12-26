// write the cpp program to find the minimum number of coins required to make the targt sum

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// solution using dp to solve this
// the below function have tc of bigO(n*sum) and sc of bigO(n*sum+1) for memorization
class Solution
{
public:
    int nfindmincoins(int i, vector<int> &coins, int t, vector<vector<int>> &memo)
    {
        if (t == 0)
            return 0;
        if (t < 0 || i == coins.size())
            return INT_MAX;

        if (memo[i][t] != -1)
            return memo[i][t];

        int take = INT_MAX;

        if (coins[i] > 0)
        {
            take = nfindmincoins(i, coins, t - coins[i], memo);
            if (take != INT_MAX)
                take++;
        }

        int noTake = nfindmincoins(i + 1, coins, t, memo);

        return memo[i][t] = min(take, noTake);
    }
};

int findMinCoins(int i, vector<int> &coins, int t)
{
    if (t == 0)
        return 0;
    if (t < 0 || i == coins.size())
        return INT_MAX;

    int take = INT_MAX;

    if (coins[i] > 0)
    {
        take = findMinCoins(i, coins, t - coins[i]);
        if (take != INT_MAX)
            take++;
    }

    int noTake = findMinCoins(i + 1, coins, t);

    return min(take, noTake);
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int target = 11;
    int n=coins.size();
    int result = findMinCoins(0, coins, target);
    int size = n*target+1;
    vector<vector<int>> memo(n, vector<int>(target+1, -1));
    Solution s;
    int r = s.nfindmincoins(0,coins,target,memo);
    
    cout<<r;

    // if (result == INT_MAX)
    // {
    //     cout << "Not possible to make the target sum with the given coins" << endl;
    // }
    // else
    // {
    //     cout << "Minimum number of coins required: " << result << endl;
    // }

    return 0;
}