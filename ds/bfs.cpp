// write the cpp program to perform the bfs operation over the graph
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int V, vector<vector<int>> &edges)
{
    // create the adj matrix
    vector<vector<int>> adj(V);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> res;
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for (int n : adj[curr])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push(n);
            }
        }
    }

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

    vector<int> res = bfs(5, edges);
    for (int i : res)
    {
        cout << i << " ";
    }
}