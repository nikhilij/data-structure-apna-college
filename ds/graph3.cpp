// wap to write dfs for graph data structure using stack and backtracking

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    int vertices;
    vector<list<int>> addList;
    vector<bool> visited;

public:
    Graph(int v)
    {
        vertices = v;
        addList.resize(vertices);
        visited.resize(vertices,false);
    }

    void addEdge(int src, int dest)
    {
        addList[src].push_back(dest);
    }

    // the code below is the iterative method for  dfs

    void dfs(int sVertex)
    {
        stack<int> s;
        s.push(sVertex);

        while (!s.empty())
        {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex])
            {
                cout << vertex << " ";
                visited[vertex] = true;
            }

            for (auto it = addList[vertex].begin(); it != addList[vertex].end(); it++)
            {
                if (!visited[*it])
                {
                    s.push(*it);
                }
            }
        }
    }

    void displayGraph() {
        for (int i = 0; i < vertices; i++) {
            std::cout << "Vertex " << i << ":";
            for (auto it = addList[i].begin(); it != addList[i].end(); ++it) {
                std::cout << " -> " << *it;
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // g.dfs(0);
    g.displayGraph();
}