// aggressive cows brute force approach

// first think of the distance between the two cause lets say 1 then 2 then 3 
// so in main function i started with the min dist between the cows 1 and check whether we place all the cows or not 
// if yes we can place then check for min dist 2 and then 3 

// now learn for binary search approach 



#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    bool check(vector<int> &stalls, int k, int dist)
    {
        int cnt = 1;
        int prev = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - prev >= dist)
            {
                prev = stalls[i];
                cnt++;
            }
        }

        return (cnt >= k);
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int res = 0;
        int minDist = 1;
        int maxDist = stalls.back() - stalls[0];
        for (int i = minDist; i <= maxDist; i++)
        {

            if (check(stalls, k, i))
            {
                res = i;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << "The largest minimum distance is: " << sol.aggressiveCows(stalls, k) << endl;
    return 0;
}