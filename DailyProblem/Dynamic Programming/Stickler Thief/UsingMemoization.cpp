#include<bits/stdc++.h>
using namespace std;

int maxLootRec(const vector<int>& arr, int n, vector<int>& memo){
    if(n <= 0) return 0;
    if(n == 1) return arr[0];
    if(memo[n] != -1) return memo[n];

    int pick = arr[n-1] + maxLootRec(arr, n-2, memo);
    int notPick = maxLootRec(arr, n-1, memo);

    memo[n] = max(pick, notPick);
    return memo[n];
}
int findMaxSum(vector<int>& arr){
    int n = arr.size();
    vector<int> memo(n+1, -1);
    return maxLootRec(arr, n, memo);
}
int main(){
    vector<int> arr = {6, 5, 5, 7, 4};
    cout << findMaxSum(arr);
    return 0;
}