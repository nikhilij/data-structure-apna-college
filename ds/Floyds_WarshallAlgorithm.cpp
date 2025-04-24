// write the cpp program for floyds warshall algorithm
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void floydWarshall(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // Initialize the distance matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Set the distance from each vertex to itself as 0
    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
    }

    // Update the distance matrix using Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}


int main()
{
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}};

    floydWarshall(graph);

    return 0;
}