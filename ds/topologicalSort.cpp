#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and topological sort
void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack, const vector<vector<int>> &adj) {
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// Function to perform topological sort on the graph
void topologicalSort(int V, const vector<vector<int>> &adj) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    // Print the topological order
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {
    // Number of vertices in the graph
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort of the given graph is:\n";
    topologicalSort(V, adj);

    return 0;
}
