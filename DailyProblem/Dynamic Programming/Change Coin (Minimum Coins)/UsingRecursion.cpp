#include<bits/stdc++.h>
using namespace std;

int minCoinRecur(int i, int sum, vector<int> &coins){
    if(sum == 0){
        return 0;
    }
    if(sum < 0 || i == coins.size()){
        return INT_MAX;
    }

    int take = INT_MAX;

    if(coins[i] > 0){
        take = minCoinRecur(i, sum-coins[i], coins);
        if(take != INT_MAX){
            take++;
        }
    }

    int noTake = minCoinRecur(i+1, sum, coins);
    return min(take, noTake);
}

int minCoins(vector<int> &coins, int sum){
    int res = minCoinRecur(0, sum, coins);
    return res != INT_MAX ? res : -1;
}
int main(){
    vector<int> coins = {9, 6, 5, 1};
    int sum = 19;
    cout << minCoins(coins, sum);
    return 0;
}