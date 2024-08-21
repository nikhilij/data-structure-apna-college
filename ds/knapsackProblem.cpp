//knapsack problem in cpp


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findMin(vector<int> cost)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (const auto &ele : cost)
    {
        minHeap.push(ele);
    }
    int currSum = 0;
    while (minHeap.size() != 1)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        currSum += first + second;
        cout << "currSum: " << currSum << "  ";
        minHeap.push(first + second);
    }
    return currSum;
}

int main()
{
    vector<int> cost = {4, 2, 3, 6};
    cout << endl;
    cout << findMin(cost) << endl;
    ;
    return 0;
}