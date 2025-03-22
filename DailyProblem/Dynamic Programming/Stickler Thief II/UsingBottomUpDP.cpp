#include<bits/stdc++.h>
using namespace std;

int maxValTab(int x, int y, vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n);

    dp[x] = arr[x];

    dp[x+1] = max(arr[x], arr[x+1]);
    for(int j=x+2;j<=y;j++){
        int take = arr[j] + dp[j-2];
        int notTake = dp[j-1];
        dp[j] = max(take, notTake);
    }
    return dp[y];
}
int maxValue(vector<int>& arr){
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    int ans = 0;
    ans = max(ans, maxValTab(0, n-2, arr));
    ans = max(ans, maxValTab(1, n-1, arr));
    return ans;
}
int main(){
    vector<int> arr = {2, 2, 3, 1, 2};
    cout << maxValue(arr);
    return 0;
}