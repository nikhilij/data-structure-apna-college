// write the program to get the longest palindromic substring from the given string using dp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestPalindrome(string &s)
{
    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    int start = 0;
    int mxlen = 1;
    // for length 1
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    // for length 2
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i+1] = 1;
            if (mxlen < 2)
            {
                start = i;
                mxlen = 2;
            }
        }
    }

    // for len more than 3
    for(int k = 3;k<=n-1;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i+k-1;
            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j]==1;
                if(mxlen<2){
                    start = i;
                    mxlen = k;
                }
            }
        }
    }

    return s.substr(start,mxlen);
}

int main()
{
    string s = "babad";
    string res = longestPalindrome(s);
    cout << res << endl;
    return 0;
}