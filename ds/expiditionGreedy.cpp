// wap to find expeidition using greedy algorithm in cpp 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Corrected lambda declaration for the comparator
auto compare = [](const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1]; // Min-heap based on fuel amount
};

int minStops(vector<vector<int>> pairs, int F, int D)
{
    int currFuel = F;
    int remDis = D;

    // Convert distances to distance from the destination
    for (auto &ele : pairs)
    {
        ele[0] = D - ele[0];
    }

    // Priority queue (min-heap) for maximum fuel at each stop
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);

    // Sort stations by their distance from the destination
    sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    int ans = 0;
    int currDis = 0;

    for (const auto &ele : pairs)
    {
        // Distance to the next station
        int nextDis = ele[0];

        // Consume fuel to reach the next station
        while (currFuel < (nextDis - currDis))
        {
            if (maxHeap.empty())
            {
                return -1; // Impossible to reach destination
            }
            currFuel += maxHeap.top()[1]; // Refuel
            maxHeap.pop();
            ans++;
        }

        // Update the current fuel and distance
        currFuel -= (nextDis - currDis);
        currDis = nextDis;

        // Push the current station's fuel amount into the heap
        maxHeap.push(ele);
    }

    // Check if we can reach the destination with the remaining fuel
    while (currFuel < remDis - currDis)
    {
        if (maxHeap.empty())
        {
            return -1; // Impossible to reach destination
        }
        currFuel += maxHeap.top()[1];
        maxHeap.pop();
        ans++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> pairs = {{5, 2}, {4, 4}, {11, 5}, {15, 10}};
    cout << minStops(pairs, 10, 25) << endl;
    return 0;
}
