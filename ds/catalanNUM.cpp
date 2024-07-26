// wap to understand catalan number 
/*
Catalan numbers are a sequence of natural numbers that have many applications in combinatorial mathematics.
The nth catalan number is typically denoted by Cn. They appear in various counting problems, often involving recursive structures.
*/

#include<iostream>
using namespace std;

int catalanNUM(int val){
    if(val<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<val;i++){
        res+=catalanNUM(i)*catalanNUM(val-i-1);
    }
    return res;
}

int main(){
    for(int i=0;i<10;i++)
        cout<<catalanNUM(i)<<" ";
}