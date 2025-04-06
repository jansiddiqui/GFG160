#include<bits/stdc++.h>
using namespace std;

void TSUtil(int v, vector<vector<int>>&adj, vector<bool> &visited, stack<int> &st){
    visited[v]=true;
    for(int i : adj[v]){
        if(!visited[i]){
            TSUtil(i, adj, visited, st);
        }
    }
    st.push(v);
}
vector<vector<int>> consAdj(int V, vector<vector<int>> &edges){
    vector<vector<int>> adj(V);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
    }
    return adj;
}

vector<int> TopoSort(int V, vector<vector<int>> &edges){
    stack<int> st;
    vector<bool> visited(V, false);
    vector<vector<int>> adj = consAdj(V, edges);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            TSUtil(i, adj, visited, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    int v = 6;
    vector<vector<int>>edges={{2,3},{3,1},{4,0},{4,1},{5,0},{5,2}};
    vector<int> ans=TopoSort(v, edges);
    for(auto node : ans){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}
