#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    vector<vector<int>> result;
    result.push_back(arr[0]);

    for(int i=1;i<arr.size();i++){
        if(arr[i][0] > result.back()[1]){
            result.push_back(arr[i]);
        }else{
            result.back()[1] = max(result.back()[1], arr[i][1]);
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> arr = {{1, 4}, {8, 6}, {2, 10}, {3, 18}};
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = mergeIntervals(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}