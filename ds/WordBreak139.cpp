#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.length()+1,false);
        dp[s.length()]=true;
        for(int i=s.length();i>=0;i--){
            for(string w:wordDict){
                if((i+w.length())<=s.length() && s.substr(i,w.length())==w){
                    dp[i]=dp[i+w.length()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};
int main() {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    if (solution.wordBreak(s, wordDict)) {
        cout << "The word can be segmented." << endl;
    } else {
        cout << "The word cannot be segmented." << endl;
    }
    return 0;
}