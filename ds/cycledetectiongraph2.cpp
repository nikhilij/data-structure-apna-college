// wap to detect the cycle in directed graph using cpp
#include <iostream>
#include <vector>

using namespace std;

class graph
{
    int vertices;
    vector<vector<int>> addList;
    vector<bool> visited;
    vector<bool> recStack;

public:
    graph(int v)
    {
        vertices = v;
        addList.resize(vertices);
        visited.resize(vertices, false);
        recStack.resize(vertices, false);
    }

    void addEdge(int src, int dest)
    {
        addList[src].push_back(dest); // for directed graph
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << vertices << " ";
            for (auto it = addList[i].begin(); it != addList[i].end(); it++)
            {
                cout << "->" << *it;
            }
            cout << endl;
        }
    }

    bool detectcycle()
    {
        for (int i = 0; i < vertices; i++)
        {
            if (iscycle(i))
            {
                return true;
            }
        }
        return false;
    }

    bool iscycle(int v)
    {
        if (!visited[v])
        {

            // mark in both
            visited[v] = true;
            recStack[v] = true;

            for (int i = 0; i < addList[v].size(); i++)
            {
                int adjVertex = addList[v][i]; // Get the adjacent vertex
                if (!visited[adjVertex] && iscycle(adjVertex))
                {
                    return true;
                }
                else if (recStack[adjVertex])
                {
                    return true;
                }
            }
        }
        recStack[v] = false;
        return false;
    }
};
int main()
{

    graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 6);
    g.addEdge(2, 7);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    g.detectcycle() ? cout << "true" : cout << "false";
}