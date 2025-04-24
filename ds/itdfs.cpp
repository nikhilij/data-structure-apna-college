#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> DFS(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> traversal;
    stack<int> stack;

    stack.push(start);

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!visited[v]) {
            traversal.push_back(v);
            visited[v] = true;
        }

        for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
            if (!visited[*it]) {
                stack.push(*it);
            }
        }
    }

    return traversal;
}

int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    int start = 0;

    vector<int> result = DFS(start, adj);

    cout << "DFS Traversal: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}