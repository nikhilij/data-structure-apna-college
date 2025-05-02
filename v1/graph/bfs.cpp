// write the cpp program to perform the bfs traversal of a graph

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> edges, int V)
{
    // create an adj list
    vector<vector<int>> adj(V + 1);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> visited(V, false);
    vector<int> res;
    queue<int> q;
    q.push(1);
    visited[1]=true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        res.push_back(curr);
        for (auto ne : adj[curr])
        {
            if (!visited[ne])
            {
                visited[ne] = true;
                q.push(ne);
            }
        }
    }
    return res;
}

int main()
{
    // Demo edge list for a simple undirected graph with 5 nodes and 6 edges
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 4},
        {4, 5}};
    int V = 5; // Number of vertices in the graph
    vector<int> result = bfs(edges, V);

    for (int i : result)
        cout << i << " ";
}