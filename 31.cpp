// another way to revers the string using recursion

#include<iostream>
using namespace std;

void reverse(string s, int i){

    if(i<0){
        return;
    }
    cout<<s[i];
    reverse(s,i-1);

}

void reverse(string &s){
    reverse(s,s.length()-1);
}
int main(){
    string s;
    cin>>s;
    reverse(s);
}