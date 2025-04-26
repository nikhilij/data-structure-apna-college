#include <iostream>
#include <vector>

using namespace std;

void dfsHelper(int node, vector<bool> &visited, vector<int> &res, vector<vector<int>> &adj)
{
    visited[node] = true;
    res.push_back(node);
    for (int n : adj[node])
    {
        if (!visited[n])
        {
            dfsHelper(n, visited, res, adj);
        }
    }
}

vector<int> dfs(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    for (auto it : edges)
    {
        // for undirected graph
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> res;
    vector<bool> visited(V, false);
    dfsHelper(0, visited, res, adj);
    return res;
}

int main()
{

    vector<vector<int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {3, 4}};

    vector<int> res = dfs(5, edges);
    for (int i : res)
    {
        cout << i << " ";
    }
}