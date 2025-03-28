#include<bits/stdc++.h>
using namespace std;

int AS(vector<int> &start, vector<int> &finish){
    int ans = 0;
    vector<vector<int>> arr;

    for(int i=0;i<start.size();i++){
        arr.push_back({finish[i], start[i]});
    }

    sort(arr.begin(), arr.end());

    int finishtime = -1;

    for(int i=0;i<arr.size();i++){
        vector<int> activity = arr[i];
        if(activity[1] > finishtime){
            finishtime = activity[0];
            ans++;
        }
    }
    return ans;
}

int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << AS(start, finish);
    return 0;
}