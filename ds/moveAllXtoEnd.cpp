// wap to move all the x to the end using recursion

#include<iostream>
using namespace std;

string movxtoend(string s){
    if(s.length()==0){
        return "";
    }

    char ch=s[0];
    string ans=movxtoend(s.substr(1));

    if(ch=='x'){
        return (ans+ch);
    }

    return (ch+ans);
}

int main(){
    string s;
    cin>>s;

    cout<<movxtoend(s);
    return 0;
}