// wap for fractional knapsack - greedy algorithm

// We are given n items with {weight, value} of each item and the capacity of knapsack (sack) 'W'. We need to put these items in knapsack such that final value of items in kanpsack is maximum
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMax(vector<vector<int>>pairs , int capacity){
    sort(pairs.begin() , pairs.end() , [](vector<int>a , vector<int>b){
        return a[1]/a[0] > b[1]/b[0];
    });

    int maxVal = 0;
    int W = capacity;

    for(const auto& ele : pairs){
        if(ele[0] <= W){
            maxVal += ele[1];
            W -= ele[0];
        }
        else{
            int temp = ele[1]/ele[0];
            maxVal += temp*W;
            W -= W;
            break;
        }
    }
    return maxVal;
}


int main(){

    vector<vector<int>> pairs = {{7,21}, {5,40} , {6,12} , {4,24} , {6,30}};

    int W = 20;

    cout<<"Max value: "<<findMax(pairs , W);

    return 0;
}