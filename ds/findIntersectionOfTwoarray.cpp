// write the cpp program to find the intersection of two array 
#include <iostream>
#include <vector>
#include <unordered_set>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
                unordered_set<int> sa(a.begin(), a.end());
                vector<int> res;
                
                for (int i = 0; i < b.size(); i++) {
                        if (sa.find(b[i]) != sa.end()) {
                                res.push_back(b[i]);
                                sa.erase(b[i]);
                        }
                }
                return res;
        }
};

int main() {
        Solution sol;
        vector<int> a = {1, 2, 3, 2, 1};
        vector<int> b = {3, 2, 2, 3, 3, 2};
        
        vector<int> result = sol.intersectionWithDuplicates(a, b);
        sort(result.begin(),result.end());
        cout << "Intersection of two arrays: ";
        for (int num : result) {
                cout << num << " ";
        }
        cout << endl;
        
        return 0;
}