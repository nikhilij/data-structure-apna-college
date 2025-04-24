// write the cpp program for kruskals algorithm

#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSet(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false;

        if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if (rank[py] < rank[px])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
};

int kruskal(int V, vector<tuple<int, int, int>> &edges)
{
    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return get<2>(a) < get<2>(b); 
    });

    DSU dsu(V);

    int mstcost=0;

    for(auto &[u,v,w]:edges){
        if(dsu.unionSet(u,v)){
            mstcost +=w;
            cout << "Edge added to MST: " << u << " - " << v << " (weight: " << w << ")\n";
        }
    }

    return mstcost;
}

int main() {
    int V = 5;
    vector<tuple<int, int, int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mstWeight = kruskal(V, edges);
    cout << "\nTotal weight of MST: " << mstWeight << endl;

    return 0;
}