#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V){
    vector<vector<vector<int>>> adj(V);
    for(const auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return adj;
}

vector<int> shortestPath(int V, vector<vector<int>> &edges, int src){
    vector<vector<vector<int>>> adj = constructAdj(edges, V);

    set<pair<int, int>>st;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()){
        auto it = *(st.begin());
        int u = it.second;

        st.erase(it);
        for(auto x : adj[u]){
            int v = x[0];
            int weight = x[1];
            if(dist[v] > dist[u] + weight){
                if(dist[v] != INT_MAX){
                    st.erase({dist[v], v});
                }
                dist[v] = dist[u] + weight;
                st.insert({dist[v], v});
            }
        }
        
    }
    return dist;
}

int main(){
    int V = 5;
    int src = 0;
    vector<vector<int>> edges = {{0,1,4},{0,2,8},{1,4,6},{2,3,2},{3,4,10}};
    vector<int> dist = shortestPath(V, edges, src);
    for(int res : dist){
        cout << res << " ";
    }
    return 0;
}