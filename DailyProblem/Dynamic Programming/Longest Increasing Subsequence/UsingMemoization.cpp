#include<bits/stdc++.h>
using namespace std;

int lisEndingAtIdx(vector<int>& arr, int idx, vector<int>& memo){
    if(idx == 0){
        return 1;
    }

    if(memo[idx] != -1){
        return memo[idx];
    }

    int mx = 1;
    for(int prev=0;prev<idx;prev++){
        if(arr[prev] < arr[idx]){
            mx = max(mx, lisEndingAtIdx(arr, prev, memo) + 1);
        }
    }
    memo[idx] = mx;
    return memo[idx];
}

int lis(vector<int>& arr){
    int n = arr.size();
    vector<int> memo(n,-1);
    int res = 1;
    for(int i=1;i<n;i++){
        res = max(res, lisEndingAtIdx(arr, i, memo));
    }
    return res;
}

int main(){
    vector<int> arr = {2, 4, 5, 8,2,4};
    cout << lis(arr);
    return 0;
}