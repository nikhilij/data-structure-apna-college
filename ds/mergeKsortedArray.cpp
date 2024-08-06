// wap to Merge K sorted array using heap
// example we have 3 sorted arrays:
// 1. -->> 1,4,7
// 2. -->> 3,5
// 3. -->> 2,6,7
// output should be -->> 1 2 3 4 5 6 7 7

// brute force approach
// take 2 arrays and merge them recursively

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// a struct to store the element value along with its array index and element index

struct Element
{
    int value;
    int arrayIndex;
    int elementIndex;
};

// function to merge k sorted arrays using min heap

vector<int> mergeKSortedArrays(const vector<vector<int>> &arrays)
{
    // create a min heap for that we need to first declare the comparison function lambda type
    auto compare = [](const Element &a, const Element &b)
    {
        return a.value > b.value;
    };

    priority_queue<Element, vector<Element>, decltype(compare)> minHeap(compare);

    // we will push the first element of each array into the min heap

    for (int i = 0; i < arrays.size(); i++)
    {
        if (!arrays.empty())
        {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Resultant merged array
    vector<int> result;

    while (!minHeap.empty())
    {
        Element current = minHeap.top();
        minHeap.pop();

        // add the smallest element to the result array
        result.push_back(current.value);

        // If there is a next element in the same array , push it to the heap

        if (current.elementIndex + 1 < arrays[current.arrayIndex].size())
        {
            minHeap.push({arrays[current.arrayIndex][current.elementIndex + 1], current.arrayIndex, current.elementIndex + 1});
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arrays = {
        {1, 5, 8},
        {2, 3, 7},
        {0, 9, 10, 11}
    };

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout<<"Merged Array: ";
    for(auto num : mergedArray){
        cout<< num << " "; 
    }
    cout<<endl;

    return 0;
}
