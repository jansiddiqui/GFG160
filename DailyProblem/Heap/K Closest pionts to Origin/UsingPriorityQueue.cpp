#include<bits/stdc++.h>
using namespace std;

int squaredDis(vector<int>& point){
    return point[0] * point[0] + point[1] * point[1];
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
    priority_queue<pair<int, vector<int>>> maxHeap;

    for(int i=0; i<points.size();i++){
        int dist = squaredDis(points[i]);

        if(maxHeap.size() < k){
            maxHeap.push({dist, points[i]});
        }else{
            if(dist < maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({dist, points[i]});
            }
        }
    }
    vector<vector<int>> res;

    while(!maxHeap.empty()){
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return res;
}
int main(){
    vector<vector<int>> points = {{1,3},{-2,2},{5,-1},{3,2},{1,1}};
    int k = 3;
    vector<vector<int>> res = kClosest(points, k);

    for(vector<int> point : res){
        cout<< "[" << point[0]<< ", " << point[1] << "] ";
    }

    return 0;
}