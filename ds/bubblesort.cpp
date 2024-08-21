// wap to bubble sort in cpp

#include<bits/stdc++.h>

using namespace std;

void bubblesort(string &s,int n){
    int swapped;
    for(int i=0;i<n-1;i++){
        swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(s[j]<s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}


int main(){
    string s="123456789";

    // sort(s.begin(),s.end(),greater<int>());
    // or you can simply use a bubble sort for sorting

    int len=s.length();
    bubblesort(s,len);

    cout<<s<<endl;
    cout<<typeid(s).name()<<endl;
    return 0;
}