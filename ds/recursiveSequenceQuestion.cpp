// Solving f(n)= (1) + (2*3) + (4*5*6) … n using Recursion

#include<iostream>
using namespace std;
const int MOD = 1000000007;
long long calc(int start,int end,int N){
    int i;
    long long curr = 1;
    if(end==N+1) return 0;
    for(i=start;i<start+end;i++){
        curr*=i;
    }
    return curr + calc(i,end+1,N);
}

long long recursiveSequence(int n){
    if(n==1) return 1;
    return calc(1,1,n)%MOD;
}

int main(){
    int n;
    cin>>n;
    cout<<recursiveSequence(n)<<endl;
}

/* class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans = 0;
        const int MOD = 1000000007;
        int start = 1;
        for(int i=1;i<=n;i++){
            long long mul = 1;
            int end = start+i-1;
            for(int j = start;j<=end;j++){
                mul = (mul*j)%MOD;
            }
            ans = (ans+mul)%MOD;
            start = end+1;
        }
        return ans;
    }
}; */