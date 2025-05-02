// write the cpp program for bellManford alogirthm to find the single source shortest path to all nodes that can hanlde negative weight and detect cycle

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanford(vector<vector<int>> edges, int V, int src = 0)
{

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0], v = it[1], w = it[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check one more time

    for (auto it : edges)
    {
        int u = it[0], v = it[1], w = it[2];
        if (!dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}

int main()
{
    // create an demo edge
    int V = 5; // number of vertices
    int m = 7; // number of edges

    // Each edge is represented as {u, v, w} where u->v has weight w
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    vector<int> dist = bellmanford(edges, V, 0);
    for (auto it : dist)
    {
        cout << it << " ";
    }
}