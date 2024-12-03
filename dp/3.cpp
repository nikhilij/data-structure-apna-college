#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    sort(arr.begin(), arr.end());

    //    vector<vector<int>> result;
    //    for(int i=0;i<arr.size();i++){
    //       for(int j=i+1;j<arr.size();j++){
    //          if(arr[i]+arr[j]==s){
    //             result.push_back({arr[i],arr[j]});
    //          }
    //       }
    //    }
    //    return result;

    // optimal approach

    // i am making hashmap for this
    unordered_map<int, int> mp;
    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        int complement = s - arr[i];

        if (mp.find(complement) != mp.end())
        {
            result.push_back({complement, arr[i]});
        }

        mp[arr[i]]++;
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int s = 5;
    vector<vector<int>> result = pairSum(arr, s);
    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}