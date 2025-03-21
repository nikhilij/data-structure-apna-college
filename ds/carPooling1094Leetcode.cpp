// write the cpp program for leetcode 1094 car pooling problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips,int capacity){
        vector<int> changes(1001,0);
        for(auto& trip : trips){
            int passenger = trip[0],from=trip[1],to=trip[2];
            changes[from]+=passenger;
            changes[to]-=passenger;
        }

        int currPassenger = 0;
        for(int passenger : changes){
            currPassenger+=passenger;
            if(currPassenger>capacity) return false;
        }

        return true;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    bool ans = sol.carPooling(trips,capacity);
    cout<<ans<<endl; // Output: false
    return 0;
}