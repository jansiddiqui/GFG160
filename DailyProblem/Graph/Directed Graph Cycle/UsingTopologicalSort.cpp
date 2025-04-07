#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>>&edges){
    vector<vector<int>> adj(V);
    for(auto &edge : edges){
        adj[edge[0]].push_back(edge[1]);
    }
    return adj;
}

bool isCyclic(int V, vector<vector<int>> &edges){
    vector<vector<int>> adj = constructAdj(V, edges);
    vector<int> inDegree(V, 0);
    queue<int> q;
    int visited = 0;
    for(int u=0;u<V;++u){
        for(int v : adj[u]){
            inDegree[v]++;
        }
    }
    for(int u=0;u<V;++u){
        if(inDegree[u] == 0){
            q.push(u);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visited++;

        for(int v : adj[u]){
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
    }
    return visited != V;
}
int main(){
    int V=4;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{2,0},{2,3}};
    cout<<(isCyclic(V, edges) ? "true" : "false") << endl;
    return 0;
}