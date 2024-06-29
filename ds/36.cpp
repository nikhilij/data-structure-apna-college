// wap to generate all the permutation of a given string 
#include<iostream>
using namespace std;

void generatePermutation(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);

        generatePermutation(ros,ans+ch);
    }
}

int main(){
    
    string s;
    cin>>s;
    string ans="";
    generatePermutation(s,ans);

    return 0;
}