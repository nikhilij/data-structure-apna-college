#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> result;
    bool Cycle = false;

    void dfs(int node){
        if(Cycle) return;
        if(visited[node]==1){
            Cycle = true;
            return;
        }
        if(visited[node]==2) return;

        visited[node]=1;
        for(int neighbor:adj[node]){
            dfs(neighbor);
        }
        visited[node]=2;
        result.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        visited.resize(numCourses,0);

        for(auto& pre : prerequisites){
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        if(Cycle) return{};

        reverse(result.begin(),result.end());
        return result;
    }
};

int main(){
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    
    vector<int> order = sol.findOrder(numCourses, prerequisites);
    
    if(order.empty()) {
        cout << "There is no possible order to complete all courses." << endl;
    } else {
        cout << "The order to complete the courses is: ";
        for(int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
