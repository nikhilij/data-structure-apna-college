// write the floyds algo to find the shortest path between every pairs of verticies of  a graph
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void FloydsWarshallAlgo(vector<vector<int>> &graph, int V)
{
    vector<vector<int>> dist = graph;
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "negative cycle is preset";
            return;
        }
    }
    cout << "Shortest distances between every pair:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int V = 4;
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    FloydsWarshallAlgo(graph,V);
}