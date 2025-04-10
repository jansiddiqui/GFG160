#include<bits/stdc++.h>
using namespace std;

// DSU = Disjoint Union Set
class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    int find(int i){
        if(parent[i] == -1){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
            }
            else if(rank[s1] < rank[s2]){
                parent[s2] = s1;
            }
            else{
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph{
    vector<vector<int>> edgelist;
    int V;

    public:
    Graph(int V){
        this-> V = V;
    }
    void addEdge(int x, int y, int w){
        edgelist.push_back({w, x, y});
    }
    int kruskalsMST(){
        sort(edgelist.begin(), edgelist.end());
        DSU s(V);
        int ans = 0;
        int count = 0;

        for(auto edge : edgelist){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(s.find(x) != s.find(y)){
                s.unite(x, y);
                ans += w;;
                count++;
            }
            if(count == V-1){
                break;
            }
        }
        return ans;
    }
};

int minCost(vector<vector<int>> &houses){
    int n = houses.size();
    Graph g(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cost = abs(houses[i][0]- houses[j][0]) + abs(houses[i][1]-houses[j][1]);
            g.addEdge(i, j, cost);
        }
    }
    return g.kruskalsMST();
}
int main(){
    vector<vector<int>> houses = {{4, 12},{15,20},{17,0}};
    cout<<minCost(houses);
    return 0;
}