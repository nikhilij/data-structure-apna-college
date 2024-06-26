// wap to find the result of n raised to power of p

#include<iostream>
using namespace std;

int findp(int n,int p){
    if(p==0){
        return 1;
    }
    return n*findp(n,p-1);
}
int main(){
    int n,p;
    cin>>n>>p;
    cout<<findp(n,p);
}