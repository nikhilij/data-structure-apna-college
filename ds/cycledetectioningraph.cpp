// wap to detect the cycle in undirected graph

#include <iostream>
#include <vector>

using namespace std;

class graph
{

    int vertices;
    vector<vector<int>> addList;
    vector<bool> visited;

public:
    graph(int v)
    {
        vertices = v;
        addList.resize(vertices);
        visited.resize(vertices,false);
    }

    void addEdge(int src, int dest)
    {
        addList[src].push_back(dest);
        addList[dest].push_back(src);
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " :";
            for (auto it = addList[i].begin(); it != addList[i].end(); it++)
            {
                cout << " -> " << *it;
            }
            cout << endl;
        }
    }

    // first keep on traversing graph for checking 
    bool checkcycle(){
        bool cycle=false;

        for(int i=0;i<vertices;i++){
            if(!visited[i] and iscycle(i,addList,-1)){
                return true;
            }
        }
        return false;
    }

    bool iscycle(int src, vector<vector<int>>,int parent){
        visited[src]=true;
        // then we will check for its neighbour
        for(auto it : addList[src]){
            if(it!=parent){
               if(visited[it]){
                    return true;
               }
               if(!visited[it] and iscycle(it,addList,src)){
                return true;
               } 
            }
        }
        return false;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    // g.display();
    g.checkcycle()?cout<<"true":cout<<"false";
}
