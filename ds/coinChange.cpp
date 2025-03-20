// write the cpp code to count the ways to make the given amount using the given coins

#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int>&coins,int amount){
    int n=coins.size(); // number of coins 

    vector<vector<int>> dp(n+1,vector<int>(amount+1,0));

    dp[0][0]=1; // since we can make 0 by selecting no coins at all
    // for the first column there is only 1 way to make the amount 0 by selecting no coins

    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }

    // now general case 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            // excluding the current coin
            dp[i][j]=dp[i-1][j];
            // including the current coin
            // condtion that we include 
            if(j - coins[i-1]>=0){
                dp[i][j]+=dp[i][j-coins[i-1]];
            }
        }
    }

    return dp[n][amount];

}


int main(){
    vector<int> coins = {1,2,3};
    int amount = 5;
    int ans = findWays(coins,amount);  
    cout<<ans<<endl;
    return 0;
}