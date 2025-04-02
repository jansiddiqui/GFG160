#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t);
    adj[t].push_back(s);
}
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res){
    visited[s] = true;
    res.push_back(s);
    for(int i : adj[s]){
        if(visited[i] == false){
            dfsRec(adj, visited, i, res);
        }
    }
}
vector<int> DFS(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    for(int i = 0; i < adj.size(); i++){
        if(visited[i] == false){
            dfsRec(adj, visited, i, res);
        }
    }
    return res;
}
int main(){
    int v = 6;
    vector<vector<int>> adj(v);
    vector<vector<int>> edges = {{1,2},{2,0},{0,3},{4,5}};
    for(auto &e : edges){
        addEdge(adj, e[0], e[1]);
    }
    vector<int> res = DFS(adj);
    for(auto it : res){
        cout << it << " ";
    }
    return 0;
}