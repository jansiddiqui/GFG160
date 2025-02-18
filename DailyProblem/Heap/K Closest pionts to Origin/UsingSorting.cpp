#include<bits/stdc++.h>
using namespace std;

static int squareDis(vector<int>& point){
    return point[0] * point[0] + point[1] * point[1];
}

static bool cmp(vector<int> &p1, vector<int> &p2){
    return squareDis(p1) < squareDis(p2);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
    sort(points.begin(), points.end(), cmp);
    return vector<vector<int>> (points.begin(), points.begin() + k);
}

int main(){
    vector<vector<int>> points = {{1,3},{-2,2},{5,-1},{3,2},{1,1}};
    int k = 3;

    vector<vector<int>> res = kClosest(points, k);

    for(vector<int> point : res){
        cout << "[" <<point[0] << ", " <<point[1] << "] ";
    }
    return 0;
}