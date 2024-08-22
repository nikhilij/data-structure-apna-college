#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Graph {
    vector<vector<tuple<int, int>>> adjList; // Edge list only needs weight and destination vertex

public:
    Graph(int v) {
        adjList.resize(v);
    }

    void addEdge(int w, int u, int v) {
        adjList[u].push_back(make_tuple(w, v)); // Add edge (w, v) to the adjacency list of vertex u
        adjList[v].push_back(make_tuple(w, u)); // for undirected graph 
    }

    void printGraph() {
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Vertex " << i << ": ";
            if (adjList[i].empty()) {
                cout << "No edges";
            } else {
                for (auto edge : adjList[i]) {
                    int w, v;
                    tie(w, v) = edge;
                    cout << "{" << w << ", " << v << "} ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(10, 0, 1);
    g.addEdge(20, 0, 4);
    g.addEdge(30, 1, 2);
    g.addEdge(40, 1, 3);
    g.addEdge(50, 1, 4);
    g.addEdge(60, 2, 3);
    g.addEdge(70, 3, 4);

    g.printGraph();

    return 0;
}
