#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;

        auto isPalindrome = [&](int left , int right){
            while(left<right){
                if(s[left]!=s[right]){
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };

        while(l<r){
            if(s[l]!=s[r]){
                return isPalindrome(l+1,r) || isPalindrome(l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "abca";
    if (solution.validPalindrome(s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}