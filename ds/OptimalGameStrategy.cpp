/* // write the cpp code for the
Optimal Strategy for a Game
Easy
0/40
Average time to solve is 15m
Contributed by
25 upvotes
Asked in companies
Problem statement
You and your friend Ninjax are playing a game of coins. Ninjax place the 'N' number of coins in a straight line.

The rule of the game is as follows:

1. Each coin has a value associated with it.

2. It’s a two-player game played against an opponent with alternating turns.

3. At each turn, the player picks either the first or the last coin from the line and permanently removes it.

4. The value associated with the coin picked by the player adds up to the total amount the player wins.
Ninjax is a good friend of yours and asks you to start first.

Your task is to find the maximum amount you can definitely win at the end of this game.

Note:

'N' is always even number.

Ninjax is as smart as you, so he will play so as to maximize the amount he wins.
Example 1:
Let the values associated with four coins be: [9, 5, 21, 7]

Let’s say that initially, you pick 9 and Ninjax picks 7.
Then, you pick 21 and Ninjax picks 5.
So, you win a total amount of (9+21), i.e. 30.

In case you would have picked up 7 initially and Ninjax would have picked 21 (as he plays optimally).
Then, you would pick 9 and Ninjax would choose 5. So, you win a total amount of (7+9), i.e. 16, which is not the maximum you can obtain.

Thus, the maximum amount you can win is 30. */

#include <bits/stdc++.h>

using namespace std;

int optimalStrategyOfGame(vector<int> coins, int n)
{

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            int a,b,c;
            // opponent picks jth coin or say i am taking ith coin
            a = (i + 1 < n && j - 1 >= 0) ? dp[i + 1][j - 1] : 0;

            // Opponent picks (i+1)th coin. or say i am taking ith coin
            b = (i + 2 < n) ? dp[i + 2][j] : 0;

            // Opponent picks (j-1)th coin. or say i am taking the jth coin
            c = (j - 2 >= 0) ? dp[i][j - 2] : 0;
            dp[i][j] = max((coins[i] + min(a, b)), (coins[j] + min(a, c)));
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<int> coins = {9, 5, 21, 7};
    int n = coins.size();

    int res = optimalStrategyOfGame(coins, n);
    cout << res;
}