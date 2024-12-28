
/**
 * @file LetterCombination.cpp
 * @brief Solution to LeetCode Problem 17: Letter Combinations of a Phone Number
 * 
 * This program provides a solution to the problem of generating all possible letter combinations 
 * that the provided digits could represent on a phone keypad. Each digit maps to a set of letters 
 * similar to the mapping on a traditional phone keypad.
 * 
 * The main class `Solution` contains a method `letterCombinations` which takes a string of digits 
 * and returns a vector of strings representing all possible letter combinations.
 * 
 * The mapping of digits to letters is as follows:
 * - '2' -> "abc"
 * - '3' -> "def"
 * - '4' -> "ghi"
 * - '5' -> "jkl"
 * - '6' -> "mno"
 * - '7' -> "pqrs"
 * - '8' -> "tuv"
 * - '9' -> "wxyz"
 * 
 * The method uses a backtracking approach to generate all possible combinations.
 * 
 * Example usage:
 * @code
 * Solution sol;
 * string digits = "23";
 * vector<string> combinations = sol.letterCombinations(digits);
 * for (const string &combination : combinations) {
 *     cout << combination << " ";
 * }
 * @endcode
 * 
 * The main function demonstrates how to use the `Solution` class to get letter combinations 
 * from user input and print them.
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char,string>mp={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        
        vector<string> result;
        string curr;

        function<void(int)> backTrack =[&](int index){
            if(index == digits.length()){
                result.push_back(curr);
                return;
            }
            string letters = mp[digits[index]];
            for(char c:letters){
                curr.push_back(c);
                backTrack(index+1);
                curr.pop_back();
            }
        };

        backTrack(0);
        return result;
    }
};
int main() {
    Solution sol;
    string digits;
    cout << "Enter digits: ";
    cin >> digits;
    vector<string> combinations = sol.letterCombinations(digits);
    cout << "Letter combinations are:\n";
    for (const string &combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}