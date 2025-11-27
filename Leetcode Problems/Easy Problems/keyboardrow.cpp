/**
 * @brief Given an array of strings `words`, this function returns the words that can be typed 
 *        using letters of the alphabet on only one row of an American keyboard.
 * 
 * @details The American keyboard is divided into three rows:
 *          - The first row consists of the characters "qwertyuiop".
 *          - The second row consists of the characters "asdfghjkl".
 *          - The third row consists of the characters "zxcvbnm".
 * 
 *        The function is case-insensitive, meaning both lowercase and uppercase letters 
 *        are treated as if they belong to the same row.
 * 
 * @example
 * Input: words = ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * Explanation: Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
 * 
 * @example
 * Input: words = ["omk"]
 * Output: []
 * Explanation: None of the words can be typed using letters from a single row.
 * 
 * @example
 * Input: words = ["adsdf", "sfd"]
 * Output: ["adsdf", "sfd"]
 * Explanation: Both words can be typed using letters from the 2nd row.
 * 
 * @constraints
 * - 1 <= words.length <= 20
 * - 1 <= words[i].length <= 100
 * - words[i] consists of English letters (both lowercase and uppercase).
 */
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<string> findWords(vector<string>& words){
        vector<int> row(26,0);
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for(char c: row1) row[c - 'a'] = 1;
        for(char c: row2) row[c - 'a'] = 2;
        for(char c: row3) row[c - 'a'] = 3;

        vector<string> result;

        for(string w:words){
            string word = w;
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            int targetRow = row[word[0] - 'a'];
            bool ok = true;

            for(char ch:word){
                if(row[ch - 'a'] != targetRow){
                    ok = false;
                    break;
                }
            }

            if(ok) result.push_back(w);
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> result = sol.findWords(words);

    cout << "Words that can be typed using one row of the keyboard: ";
    for(const string& word : result){
        cout << word << " ";
    }
    cout << endl;

    return 0;
}