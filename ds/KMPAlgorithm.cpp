// write the cpp program to demonstrate the kmp algorithm

#include <iostream>
#include<vector>

using namespace std;

vector<int> findlps(string s) {
    int n = s.size();
    int lenlps = 0;
    int i = 1;
    vector<int> lps(n, 0);

    while (i < n) {
        if (s[i] == s[lenlps]) {
            lps[i] = lenlps + 1;
            lenlps++;
            i++;
        }
        else {
            if (lenlps != 0) {
                lenlps = lps[lenlps - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string text, string pat) {
    vector<int> lps = findlps(pat);
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == m) return true;
        if (i < n && text[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return false;
}

bool arerotated(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    if (s1.empty() && s2.empty()) {
        return true; // Both empty
    }
    string concat = s1 + s2;
    return kmp(concat, s2);
}

int main()
{
    string s1 = "abcd";
    string s2 = "cdab";

    if (arerotated(s1, s2)) {
        cout << "Yes ";
    }
    else {
        cout << "No";
    }
}