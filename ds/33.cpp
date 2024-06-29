// wap to remove all the duplicates from the string
#include<iostream>
using namespace std;

string deduplicates(string s){
    if(s.length()==0){
        return "";
    }

    char ch=s[0];
    string ans= deduplicates(s.substr(1));

    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}

int main(){
    string s;
    cin>>s;
    cout<<deduplicates(s);
}