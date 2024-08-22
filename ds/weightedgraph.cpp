//wap to create weighted graph 

#include<iostream>
#include<vector>

using namespace std;

class graph{
    vector<vector<pair<int,int>>> addList;

    public:
    graph(int n){
        addList.resize(n);
    }

    void addEdge(int src,int dest,int weight){
        addList[src].emplace_back(dest,weight);
        addList[dest].emplace_back(src,weight); // for undirected graph
    }

    void printGraph(){
        for(int i=0;i<addList.size();i++){
            cout<<"Vertex "<<i<<":";
            for(auto &it : addList[i]){
                cout<<" -> "<< it.first<<" ( weight: "<<it.second<<" ) ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n = 4;

    graph g(n);

    g.addEdge(0,1,4);
    g.addEdge(0,2,3);
    g.addEdge(1,2,5);
    g.addEdge(1,3,2);
    g.addEdge(2,3,7);

    g.printGraph();

    
}