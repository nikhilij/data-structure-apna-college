// #include <iostream>
// #include <vector>
// #include <queue>
// #include <utility>   // for std::pair
// #include <limits>    // for INT_MAX
// #include <tuple>

// using namespace std;

// int PrimsAlgo(vector<vector<pair<int, int>>> &adj, int V)
// {
//     vector<int> key(V, INT_MAX);
//     vector<bool> inMST(V, false);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     key[0] = 0;
//     pq.push({0, 0}); // {key, vertex}
//     int mstCost = 0;

//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();

//         if (inMST[u])
//             continue;

//         inMST[u] = true;
//         mstCost += key[u];

//         for (auto &edge : adj[u])
//         {
//             int v = edge.first;
//             int wt = edge.second;

//             if (!inMST[v] && wt < key[v])
//             {
//                 key[v] = wt;
//                 pq.push({key[v], v});
//             }
//         }
//     }

//     return mstCost;
// }

// int main()
// {
//     int V = 5;
//     vector<vector<pair<int, int>>> adj(V);

//     vector<tuple<int, int, int>> edges{
//         {0, 1, 2},
//         {0, 3, 6},
//         {1, 2, 3},
//         {1, 3, 8},
//         {1, 4, 5},
//         {2, 4, 7},
//         {3, 4, 9}};

//     for (const auto &edge : edges)
//     {
//         int u, v, w;
//         std::tie(u, v, w) = edge;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w}); // Since it's an undirected graph
//     }

//     int mstCost = PrimsAlgo(adj, V);
//     cout << "Total weight of Minimum Spanning Tree: " << mstCost << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int PrimsAlgo(vector<vector<pair<int, int>>> &adj, int V)
{
    vector<bool> inMST(V, false);
    vector<int> mst(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0}); // distance vertex
    mst[0] = 0;
    int minCost = 0;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int u = curr.second;

        if (inMST[u])
        {
            continue;
        }
        inMST[u] = true;
        minCost += mst[u];

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (!inMST[v] && w < mst[v])
            {
                mst[v] = w;
                pq.push({mst[v],v});
            }
        }
    }
    return minCost;
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    vector<tuple<int, int, int>> edges{
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};

    for (const auto &edge : edges)
    {
        int u, v, w;
        std::tie(u, v, w) = edge;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since it's an undirected graph
    }

    int mincost = PrimsAlgo(adj, V);
    cout << "Total cost = " << mincost;
    return 0;
}