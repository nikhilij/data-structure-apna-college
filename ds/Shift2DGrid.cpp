// write the cpp program to shift the elements of 2d grid by k times 
#include<iostream>
#include<algorithm>
using namespace std;

#include <vector>
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> oneD;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                oneD.push_back(grid[i][j]);
            }
        }
        k%=n*m;
        reverse(oneD.begin(),oneD.end());
        reverse(oneD.begin(),oneD.begin()+k);
        reverse(oneD.begin()+k,oneD.end());

        // both will work
        // for(int i=0;i<n*m;i++){
        //     grid[i/m][i%m]=oneD[i];
        // }

        // both will work 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=oneD[i*m+j];
            }
        }
        return grid;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;
    vector<vector<int>> result = sol.shiftGrid(grid, k);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}