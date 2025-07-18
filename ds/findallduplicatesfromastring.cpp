// write the cpp program to find the duplicates in a given string
#include <iostream>
using namespace std;

void findallduplicates(string s){
    int freq[26]={0};
    for(char ch : s){
        freq[ch-'a']++;
    }

    for(int i=0;i<26;i++){
        if(freq[i]>1)
        {
            cout << (char)(i + 'a') << " ";
        }
    }
}

int main()
{
    string s = "GeeksforGeeks";
    findallduplicates(s);
}