// wap  to check whether a graph is bipartite or not
#include <iostream>
#include <vector>

using namespace std;

class graph
{
    int vertices;
    vector<vector<int>> addList;
    vector<bool> visited;
    vector<int> col; // 0 for red // 1 for blue
public:
    graph(int v)
    {
        vertices = v;
        addList.resize(vertices);
        visited.resize(vertices, false);
        col.resize(vertices, -1);
    }

    // created an undirected graph for this
    void addEdge(int src, int dest)
    {
        addList[src].push_back(dest);
        addList[dest].push_back(src);
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " ";
            for (auto it = addList[i].begin(); it != addList[i].end(); it++)
            {
                cout << " -> " << *it;
            }
            cout << endl;
        }
    }

    bool color(int v, int c)
    {
        col[v] = c;
        visited[v] = true;

        for (int i = 0; i < addList[v].size(); i++)
        {
            int vertex = addList[v][i];
            if (!visited[vertex])
            {
                if (!color(vertex, c ^ 1))
                {
                    return false;
                }
            }
            else if (col[vertex] == col[v])
            {
                return false;
            }
        }

        return true;
    }
    bool checkbipartite()
    {
        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                if (!color(i, 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.checkbipartite()?cout<<"true":cout<<"false";
}