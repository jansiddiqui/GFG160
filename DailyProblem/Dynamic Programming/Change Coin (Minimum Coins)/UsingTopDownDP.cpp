#include<bits/stdc++.h>
using namespace std;

int minCoinRecur(int i, int sum, vector<int> &coins, vector<vector<int>> &memo){
    if(sum == 0){
        return 0;
    }
    if(sum < 0 || i == coins.size()){
        return INT_MAX;
    }
    if(memo[i][sum] != -1){
        return memo[i][sum];
    }
    int take = INT_MAX;
    if(coins[i]>0){
        take = minCoinRecur(i, sum-coins[i], coins, memo);
        if(take != INT_MAX){
            take++;
        }
    }
    int noTake = minCoinRecur(i+1, sum, coins, memo);
    return memo[i][sum] = min(take, noTake);
}
int minCoins(vector<int> &coins, int sum){
    vector<vector<int>> memo(coins.size(), vector<int>(sum+1, -1));
    int res = minCoinRecur(0, sum, coins, memo);
    return res != INT_MAX ? res : -1;
}
int main(){
    vector<int> coins = {9,6,5,1};
    int sum = 19;
    cout << minCoins(coins, sum);
    return 0;
}