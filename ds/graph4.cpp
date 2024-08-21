// wap to find the number of connected components in a given graph in cpp 
#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class graph{
    int vertices;
    vector<list<int>> addList;
    vector<bool> visited;
    public:
    graph(int v){
        vertices=v;
        addList.resize(vertices);
        visited.resize(vertices,false);
    }

    void addEdge(int src, int dest){
        addList[src].push_back(dest);
        addList[dest].push_back(src);
    }


    void display(){
        for(int i=0;i<vertices;i++){
            cout<<i<<": ";
            for(auto it = addList[i].begin();it!=addList[i].end();it++){
                cout<<" -> "<<*it;
            }
            cout<<endl;
        }
    }


    void dfs(int v){
        stack<int> s;
        visited[v]=true;
        s.push(v);
        while(!s.empty()){
            int vertex=s.top();
            s.pop();
            for (auto it = addList[vertex].begin(); it != addList[vertex].end(); it++)
            {
                if (!visited[*it])
                {
                    s.push(*it);
                    visited[*it]=true;
                }
            }
            
        }

    }

    void dfsutil(){
        int cc=0;
        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                dfs(i);
                cc++;
            }
        }

        cout<< cc;
    }
};


int main(){
    graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.display();

    cout<<endl;
    cout<<endl;

    g.dfsutil();

}