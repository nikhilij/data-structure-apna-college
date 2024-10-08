// wap to find the longest Palindromic Substring from the given string 

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLength = 1;

        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (single character center)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (two-character center)
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2; // Update start index
            }
        }

        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Return the length of the palindrome
    }
};

int main() {
    Solution solution;
    string input = "babad";
    string result = solution.longestPalindrome(input);
    cout << "The longest palindromic substring is: " << result << endl;
    return 0;
}
