// write the cpp program to calculate the number of ways the given expression can evaluate to true

#include<bits/stdc++.h>
using namespace std;

int countways(string s) {
    string symbols = "";
    string operators = "";

    for (auto ch : s) {
        if (ch == 'T' || ch == 'F') symbols.push_back(ch);
        else if (ch == '&' || ch == '|' || ch == '^') operators.push_back(ch);
    }
    int n = symbols.size();
    if (n == 0) return 0; // No symbols, no ways to evaluate

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    // dp[i][j][isTrue] means number of ways to evaluate symbols[i..j] to isTrue (1 for true, 0 for false)
    // Example:
    // dp[0][2][1] = number of ways to evaluate symbols from index 0 to 2 to true
    // dp[1][3][0] = number of ways to evaluate symbols from index 1 to 3 to false
    /*
    Example representation of the 3D dp array:
    Suppose symbols = "TFT", so n = 3.
    dp will look like:
    {
        {
            {ways_T_0_0, ways_F_0_0}, // dp[0][0][1], dp[0][0][0]
            {ways_T_0_1, ways_F_0_1}, // dp[0][1][1], dp[0][1][0]
            {ways_T_0_2, ways_F_0_2}  // dp[0][2][1], dp[0][2][0]
        },
        {
            {ways_T_1_0, ways_F_1_0},
            {ways_T_1_1, ways_F_1_1},
            {ways_T_1_2, ways_F_1_2}
        },
        {
            {ways_T_2_0, ways_F_2_0},
            {ways_T_2_1, ways_F_2_1},
            {ways_T_2_2, ways_F_2_2}
        }
    }
    Where ways_T_i_j is the number of ways to evaluate symbols[i..j] to true,
    and ways_F_i_j is the number of ways to evaluate symbols[i..j] to false.
    */
    for (int gap = 0; gap < n;gap++) {
        for (int i = 0, j = gap; i < n - gap; i++, j++) {
            if (gap == 0) {
                dp[i][j][1] = (symbols[i] == 'T');
                dp[i][j][0] = (symbols[i] == 'F');
            } else {
                for (int k = i; k < j; ++k) {
                    int left_true = dp[i][k][1];
                    int left_false = dp[i][k][0];
                    int right_true = dp[k + 1][j][1];
                    int right_false = dp[k + 1][j][0];

                    char op = operators[k];

                    if (op == '&') {
                        dp[i][j][1] += left_true * right_true;
                        dp[i][j][0] += (left_true * right_false) + (left_false * right_true) + (left_false * right_false);
                    }
                    else if (op == '|') {
                        dp[i][j][1] += (left_true * right_true) + (left_true * right_false) + (left_false * right_true);
                        dp[i][j][0] += left_false * right_false;
                    }
                    else if (op == '^') {
                        dp[i][j][1] += (left_true * right_false) + (left_false * right_true);
                        dp[i][j][0] += (left_true * right_true) + (left_false * right_false);
                    }
                }
            }
        }
    }
    return dp[0][n - 1][1];
}
int main() {
    string s = "T|F&T";

    cout << "Number of ways to get true: " << countways(s) << endl;
    return 0;
}   