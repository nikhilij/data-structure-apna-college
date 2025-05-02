// write the cpp program to do the dfs traversal of the graph

#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<int> &res,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node]=true;
    res.push_back(node);
    for(auto ne : adj[node]){
        if(!visited[ne]){
            dfsHelper(ne,res,adj,visited);
        }
    }
}

    vector<int> dfs(int V, vector<vector<int>> edges)
{
    vector<vector<int>> adj(V + 1);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> res;
    vector<bool> visited(V,false);
    dfsHelper(1, res, adj,visited);
    return res;
}

int main()
{
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 4},
        {4, 5}};
    int V = 5;

    vector<int> res = dfs(V, edges);

    for (auto i : res)
    {
        cout << i << " ";
    }
}