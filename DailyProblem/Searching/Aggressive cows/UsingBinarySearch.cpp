#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &stalls, int k, int dist){
    int cnt = 1;
    int prev = stalls[0];
    for(int i = 1; i< stalls.size(); i++){
        if(stalls[i] - prev >= dist){
            prev = stalls[i];
            cnt++;
        }
    }
    return (cnt >= k);
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int res = 0;
    int lo = 1;
    int hi = stalls.back() - stalls[0];
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(stalls, k, mid)){
            res = mid;
            lo =mid+1;
        }
        else{
            hi = mid -1;
        }
    }
    return res;
}
int main(){
    vector<int> st = {1, 2, 4, 8, 9};
    int k = 3;
    int ans = aggressiveCows(st, k);
    cout<<ans;
    return 0;
}