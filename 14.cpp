#include<iostream>
using namespace std;

int getbit(int n,int i){
    return ((n&(1<<i))!=0);
}

int setbit(int n, int i){
    return ((n|(1<<i)));
}

int clearbit(int n, int i){
    return(n&~(1<<i));
}

int updatebit(int n, int i,int val){
    //clearbit
    int msk=~(1<<i);
    n= n & msk;

    return(n|(val<<i)); //setnit
}
int main(){
    cout<<getbit(5,2)<<endl;
    cout<<setbit(5,1)<<endl;
    cout<<clearbit(5,2)<<endl;
    cout<<updatebit(5,1,1)<<endl;
    return 0;
}