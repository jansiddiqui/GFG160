#include<bits/stdc++.h>
using namespace std;

int cntRecur(vector<int>& coins, int n, int sum, vector<vector<int>> &memo){
    if(sum == 0){
        return 1;
    }

    if(sum < 0 || n == 0){
        return 0;
    }

    if(memo[n-1][sum] != -1){
        return memo[n-1][sum];
    }

    return memo[n-1][sum] = cntRecur(coins, n, sum - coins[n-1], memo) + cntRecur(coins, n-1, sum, memo);
}

int cnt(vector<int> &coins, int sum){
    vector<vector<int>> memo(coins.size(), vector<int>(sum+1, -1));
    return cntRecur(coins, coins.size(), sum, memo);
}

int main(){
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << cnt(coins, sum);
    return 0;
}