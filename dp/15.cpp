// program for creation of lps in cpp

#include <iostream>
#include <vector>
using namespace std;

vector<int> findLPS(string s)
{
    vector<int> lps(s.size(), 0);
    int n = s.size();
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

int findfirstOccuerence(string txt, string s)
{
    vector<int> lps = findLPS(s);
    int i = 0, j = 0;
    int n = txt.size();
    while (i < n)
    {
        if (txt[i] == s[j])
        {
            i++;
            j++;
            if (j == s.size())
            {
                return i - j;
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0 && txt[i] != s[j])
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return -1;
}

int main()
{
    string txt = "hello";
    string s = "ll";

    cout << findfirstOccuerence(txt, s);
}