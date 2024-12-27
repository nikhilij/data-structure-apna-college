// write the cpp program to find the number of pairs with given sum target
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int countPairs(vector<int> &arr, int target)
{
    // Code here
    int count = 0;
    unordered_map<int, int> mp;
    for (int n : arr)
    {
        if (mp.find(target - n) != mp.end())
        {
            count += mp[target - n];
        }
        mp[n]++;
    }
    return count;
}


int main(){
    vector<int> arr = {1, 5, 7, 1};
    int target = 6;
    cout << "Count of pairs is " << countPairs(arr, target) << endl;
    return 0;
}