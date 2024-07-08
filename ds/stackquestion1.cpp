// wap to reverse a sentence using stacks in cpp
#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' '){
            word+=s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

// other way to do it using sstream

void reverseSentence2(string s){
    stringstream ss(s);
    string word;
    
    stack<string> words;

    while(ss >> word){
        words.push(word);
    }

    while(!words.empty()){
        cout<<words.top()<<" ";
        words.pop();
    }
    cout<<endl;
}


int main(){
    string s="Hey how are you doing ";
    // reverseSentence(s);
    reverseSentence2(s);
}