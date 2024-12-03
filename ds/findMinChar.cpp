// write the program to find the minimum characters to be inserted to make the string palindrome

// write the program to find the lps of a given string

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLps(string &s)
{

    string rev = s;
    reverse(rev.begin(), rev.end());
    string concat = s + '#' + rev;
    int n = concat.length();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;)
    {
        if (concat[i] == concat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return lps;
}

int findMinChar(string &s)
{
    vector<int> lps = findLps(s);
    return s.length() - lps.back();
}

int main()
{
    string s = "aacecaaaa";
    vector<int> res = findLps(s);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << findMinChar(s);
    return 0;
}