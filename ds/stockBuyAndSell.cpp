/// write the cpp program to find the maximum profit that can be earned 
/* Stock buy and sell
Difficulty: MediumAccuracy: 29.18%Submissions: 285K+Points: 4Average Time: 20m
Given an array arr[] denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Examples:

Input: arr[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210 Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655 Maximum Profit  = 210 + 655 = 865
Input: arr[] = [4, 2, 2, 2, 4]
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2
Input: arr[] = [4, 2]
Output: 0
Explanation: Don't Buy the stock. */

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {100, 180, 260, 310, 40, 535, 695};
    int n = arr.size();
    int profit = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            profit+=arr[i]-arr[i-1];
        }
    }

    // we can also do that by selling and buying the stock on local minima and local maxima

    int res = 0;
    int i=0;
    while(i<n){
        while(i<n && arr[i]>=arr[i+1]){
            i++;
        }
        int localMin = arr[i];
        while(i<n && arr[i]<=arr[i+1]){
            i++;
        }
        int localMax = arr[i];

        res=res + localMax - localMin;
    }

    cout<< "max profit " << res<<endl;


    // cout<< "max profit " << profit<<endl;
}