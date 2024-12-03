// write a  cpp program to find the longest substr from a given string without repeating characters
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string longestSubstrDistinct(string s)
    {
        int start = 0;
        int maxLen = 0;

        unordered_set<char> seen;
        int longest_start=0;
        for (int end = 0; end < s.length(); end++)
        {
            while (seen.find(s[end]) != seen.end())
            {
                seen.erase(s[start]);
                start++;
            }

            seen.insert(s[end]);
            
            if(maxLen < end - start+1){
                maxLen = end - start+1;
                longest_start = start;
            }
        }
        return s.substr(longest_start, maxLen);
    }
};

int main()
{
    Solution s;
    string str = "geeksforgeeks";
    cout << s.longestSubstrDistinct(str) << endl;
    return 0;
}
