#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<int> &res){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for(int x : adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

vector<int> bfsDisconnected(vector<vector<int>>& adj){
    int V = adj.size();
    vector<int> res;
    vector<bool>visited(V, false);
    for(int i=0;i<adj.size();++i){
        if(!visited[i]){
            bfs(adj, i, visited, res);
        }
    }
    return res;
}
int main(){
    vector<vector<int>> adj = {{1, 2}, {0}, {0}, {4}, {3, 5}, {4}};
    vector<int> res = bfsDisconnected(adj);
    cout << "BFS Traversal: ";
    for(int i : res){
        cout << i << " ";
    }
}