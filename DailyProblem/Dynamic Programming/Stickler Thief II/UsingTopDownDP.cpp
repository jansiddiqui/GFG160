#include<bits/stdc++.h>
using namespace std;

int maxValRec(vector<int> &arr, int i, int j, vector<int> &memo){
    if(i>j) return 0;
    if(i == j) return arr[i];
    if(memo[j]!=-1) return memo[j];

    int pick = arr[j] + maxValRec(arr, i, j-2, memo);
    int notPick = maxValRec(arr, i, j-1, memo);
    return memo[j] = max(pick, notPick);
}
int maxValue(vector<int>& arr){
    int n = arr.size();
    int ans = 0;
    vector<int> memo(n-1);
    ans = max(ans, maxValRec(arr, 0, n-2, memo));

    for(int i=0; i<n; i++){
        memo[i] = -1;
    }

    ans = max(ans, maxValRec(arr, 1, n-1, memo));
    return ans;
}

int main(){
    vector<int> arr = {2,2,3,1,2};
    cout<<maxValue(arr);
    return 0;
}