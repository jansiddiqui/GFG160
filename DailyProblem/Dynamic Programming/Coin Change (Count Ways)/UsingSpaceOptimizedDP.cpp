#include<bits/stdc++.h>
using namespace std;

int cnt(vector<int> &coins, int sum){
    int n = coins.size();
    vector<int> dp(sum+1);
    dp[0] = 1;
    for(int i = 0;i<n;i++){
        for(int j=coins[i];j<=sum;j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    return dp[sum];
}
int main(){
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout<<cnt(coins, sum);
    return 0;
}