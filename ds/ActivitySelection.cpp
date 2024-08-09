// you are given n activites with their start and finish times. select the maximum number of activites that can be performed by a single person, assuming that a person can only work on a single activity at a time

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

vector<vector<int>> findPairs(vector<vector<int>> activity)
{

    sort(activity.begin(), activity.end(), compare);

    for (auto const &it : activity)
    {
        cout << it[0] << " , " << it[1] << endl;
    }

    vector<vector<int>> result;
    result.push_back(activity[0]);
    int previous = 0;

    for (int i = 1; i < activity.size(); i++)
    {
        if (activity[i][0] > activity[previous][1])
        {
            previous = i;
            result.push_back(activity[i]);
        }
    }

    return result;
}

int main()
{

    // vector<int> ele = {(1, 3), (2, 5), (4, 7), (6, 9), (8, 11), (10, 13)};
    vector<vector<int>> activity = {{2, 5}, {1, 3}, {4, 7}, {6, 9}, {10, 13}, {8, 11}};

    vector<vector<int>> ans = findPairs(activity);

    cout << endl;
    cout << "Ans: " << endl;

    for (auto const &it : ans)
    {
        cout << it[0] << " , " << it[1] << endl;
    }

    cout << "max no of tasks : " << ans.size() << endl;

    return 0;
}