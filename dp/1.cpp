// Sort people names according to their heights in cpp 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(int a, int b, const vector<int>& heights) {
        return heights[a] > heights[b];
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> indices(names.size());

        for (int i = 0; i < names.size(); i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return compare(a, b, heights);
        });

        vector<string> sortedNames(names.size());
        for (int i = 0; i < names.size(); i++) {
            sortedNames[i] = names[indices[i]];
        }
        return sortedNames;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<string> names1 = {"Mary", "John", "Emma"};
    vector<int> heights1 = {180, 165, 170};
    vector<string> result1 = sol.sortPeople(names1, heights1);

    cout << "Sorted names (Example 1): ";
    for (const auto& name : result1) {
        cout << name << " ";
    }
    cout << endl;

    // Example 2
    vector<string> names2 = {"Alice", "Bob", "Bob"};
    vector<int> heights2 = {155, 185, 150};
    vector<string> result2 = sol.sortPeople(names2, heights2);

    cout << "Sorted names (Example 2): ";
    for (const auto& name : result2) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}
