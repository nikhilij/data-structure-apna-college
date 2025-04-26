// wap to create graph and use bfs traversal in cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>

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
        visited.resize(vertices, false);
    }

    void addEdge(int src, int dest)
    {
        addList[src].push_back(dest);
        // addList[dest].push_back(dest);
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "vertices " << i << ": ";
            for (auto it = addList[i].begin(); it != addList[i].end(); it++)
            {
                cout << "-> " << *it;
            }
            cout << endl;
        }
    }

    void bfs(int sVertex)
    {
        queue<int> q;
        visited[sVertex] = true;
        q.push(sVertex);

        while (!q.empty())
        {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();
            for (auto it = addList[vertex].begin(); it != addList[vertex].end(); it++)
            {
                if (!visited[*it])
                {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // g.display();
    g.bfs(0);
}
