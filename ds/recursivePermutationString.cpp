// program to generate all permutation of given string uniquely
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void permute(string &s, int left, int right, vector<string> &res)
    {
        if (left == right)
        {
            res.push_back(s);
        }
        else
        {
            unordered_set<char> used;
            for (int i = left; i <= right; i++)
            {
                if (used.find(s[i]) == used.end())
                {
                    used.insert(s[i]);
                    swap(s[i], s[left]);
                    permute(s, left + 1, right, res);
                    swap(s[i], s[left]);
                }
            }
        }
    }

    vector<string> findPermutation(string &s)
    {
        // Code here there
        vector<string> res;

        permute(s, 0, s.length() - 1, res);
        return res;
    }
};

int main()
{
    string s;
    s = "abc";
    Solution sol;
    vector<string> permutations = sol.findPermutation(s);

    for (const string &perm : permutations)
    {
        cout << perm << endl;
    }

    return 0;
}