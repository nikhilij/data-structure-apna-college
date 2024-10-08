// wap to find the longest Non repeating substring in the given string .. leetcode question 3


#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;  // use char instead of int for character storage
        int maxlength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            // Shrink the window if the character is already in the set
            while (charSet.find(s[end]) != charSet.end()) {
                charSet.erase(s[start]);
                ++start;
            }

            // Add the character to the set
            charSet.insert(s[end]);
            
            // Update the maximum length
            maxlength = max(maxlength, end - start + 1);
        }
        return maxlength;
    }
};

// Main function
int main() {
    Solution solution;

    // Input string
    string input;
    cout << "Enter the string: ";
    // Enter the string: abcabcbb

    cin >> input;

    // Call the function to find the longest substring without repeating characters
    int result = solution.lengthOfLongestSubstring(input);

    // Output the result
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
