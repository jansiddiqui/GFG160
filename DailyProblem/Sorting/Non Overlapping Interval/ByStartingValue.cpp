#include<bits/stdc++.h>
using namespace std;

int minRemoval(vector<vector<int>>& intervals){
    int cnt = 0;
    sort(intervals.begin(), intervals.end());
    int end = intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0] < end){
            cnt++;
            end = min(intervals[i][1], end);
        }
        else{
            end = intervals[i][1];
        }
    }
    return cnt;
}
int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10}};
    cout<<minRemoval(intervals)<<endl;
}