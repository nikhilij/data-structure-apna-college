// write the cpp program to generate all the subsets of a given array using recursion

#include <iostream>
#include <vector>
using namespace std;

void generate(int n, int index, vector<int> &subset, vector<vector<int>> &Allsubset, int arr[])
{
    // base case if index == n then we get the subset
    if (index == n)
    {
        Allsubset.push_back(subset);
        return;
    }

    // exclude the current element
    generate(n, index + 1, subset, Allsubset, arr);

    // include the current element
    subset.push_back(arr[index]);
    generate(n, index + 1, subset, Allsubset, arr);

    subset.pop_back();
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> subset;
    vector<vector<int>> allSubsets;
    cout << "All subsets of the array are:\n";

    generate(n, 0, subset, allSubsets, arr);

    for (auto sub : allSubsets)
    {
        cout << "{";
        for (int num : sub)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}