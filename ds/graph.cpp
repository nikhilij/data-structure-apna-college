#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    int vertices;
    std::vector<std::list<int>> adjList;

public:
    // Constructor to initialize graph with a given number of vertices
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        // adjList[dest].push_back(src); // Uncomment this line for an undirected graph
    }

    // Function to display the graph
    void displayGraph() {
        for (int i = 0; i < vertices; i++) {
            std::cout << "Vertex " << i << ":";
            for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it) {
                std::cout << " -> " << *it;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Creating a graph with 5 vertices
    Graph g(4);

    // Adding edges
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(3,2);
    g.addEdge(1,3);

    // Displaying the graph
    g.displayGraph();

    return 0;
}
