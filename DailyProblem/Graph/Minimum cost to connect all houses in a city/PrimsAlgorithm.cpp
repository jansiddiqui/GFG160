#include<bits/stdc++.h>
using namespace std;

int manhattanDistance(vector<int> &a, vector<int>& b){
    return abs(a[0]-b[0]) + abs(a[1]-b[1]);
}
int minCost(vector<vector<int>>& houses){
    int n = houses.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    vector<bool> visited(n, false);
    minHeap.push({0,0});
    int totalCost = 0;

    while(!minHeap.empty()){
        pair<int, int> p = minHeap.top();
        minHeap.pop();
        int cost = p.first;
        int u = p.second;

        if(visited[u]) continue;

        visited[u] = true;
        totalCost += cost;

        for(int v=0;v<n;++v){
            if(!visited[v]){
                int dist = manhattanDistance(houses[u], houses[v]);
                minHeap.push({dist, v});
            }
        }
    }
    return totalCost;
}
int main(){
    vector<vector<int>> houses = {{0,7},{0,9},{20,7},{30,7},{40, 70}};
    int res = minCost(houses);
    cout <<res<<endl;
    return 0;
}