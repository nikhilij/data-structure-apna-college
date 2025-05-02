// write the cpp program for dijkstra algorithm to find the shortest path from source to other nodes in a weighted graph using a greedy apporach

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(vector<vector<int>> edges, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // creation of the adj list
    vector<vector<pair<int, int>>> adj(V);
    for (auto it : edges)
    {
        int u = it[0], v = it[1], w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // now i have my adj list i can proceed further
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // this will create the min heap
    pq.push({dist[src], src});

    // now i will go to each node and relax it

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int u = curr.second;
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    // Example weighted graph: (u, v, w) means edge from u to v with weight w
    // Let's create a graph with 5 nodes (0 to 4)
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}};
    int V = 5;
    vector<int> dist = dijkstraAlgo(edges, V, 0);
    for (int i : dist)
    {
        cout << i << " ";
    }
}