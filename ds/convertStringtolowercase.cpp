// wap to convert the string to lowercase in cpp

#include<bits/stdc++.h>
using namespace std;

int main(){


    string s;
    getline(cin,s);

    // for(int i=0;i<s.length();i++){
    //     if(s[i]>=97)
    //     s[i]=s[i]-32;// this will convert the string to all uppercase
    // }


    // for(int i=0;i<s.length();i++){
    //     if(s[i]>=65 && s[i]<=91){
    //         s[i]=s[i]+32; // this will convert the string to all to lowercase
    //     }
    // }

    transform(s.begin(),s.end(),s.begin(),::tolower); // this will transform the string into upper or lowercase

    

    cout<<s;

    
}