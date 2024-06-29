// wap to reverse the string using recursion

#include<iostream>
using namespace std;

void reverse(string s) {
    if (s.length() == 0) {
        return;
    }
    cout << s[s.length() - 1];  // Print the last character
    reverse(s.substr(0, s.length() - 1));  // Recur with the rest of the string
}



int main() {
    string s;
    cin >> s;
    reverse(s);
    return 0;
}
