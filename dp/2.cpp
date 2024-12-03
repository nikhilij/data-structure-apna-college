#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> arr) {
        if (arr.empty()) return "";

        string longest_prefix = arr[0];
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            int j = 0;
            while (j < longest_prefix.length() && j < arr[i].length() && longest_prefix[j] == arr[i][j]) {
                j++;
            }
            longest_prefix = longest_prefix.substr(0, j);
            if (longest_prefix.empty()) break;
        }

        return longest_prefix;
    }
};

int main() {
    Solution solution;
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    cout << solution.longestCommonPrefix(arr) << endl;
    return 0;
}
