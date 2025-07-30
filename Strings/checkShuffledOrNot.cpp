// Check if a string is a valid shuffle of two distinct strings

#include<iostream>  
#include<string>
using namespace std;


bool checkShuffle(const string& s1, const string& s2, const string& s3) {
    if (s1.length() + s2.length() != s3.length()) {
        return false; // Lengths do not match
    }

    int i = 0, j = 0, k = 0;

    while(k<s3.length()){
        if(i<s1.length() && s1[i]==s3[k]) i++;
        else if(j<s2.length() && s2[j]==s3[k]) j++;
        else return false;
        k++;
    }

    return true;
}

int main(){
    string s1 = "abc";
    string s2 = "def";
    string s3 = "dabcef";
    bool  res = checkShuffle(s1, s2, s3);

    if (res) {
        cout << "The string \"" << s3 << "\" is a valid shuffle of \"" << s1 << "\" and \"" << s2 << "\"." << endl;
    } else {
        cout << "The string \"" << s3 << "\" is NOT a valid shuffle of \"" << s1 << "\" and \"" << s2 << "\"." << endl;
    }
}

