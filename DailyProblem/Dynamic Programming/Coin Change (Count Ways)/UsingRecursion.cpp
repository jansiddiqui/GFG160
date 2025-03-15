#include<bits/stdc++.h>
using namespace std;


int cntRecur(vector<int>& coins, int n, int sum){
    if(sum == 0){
        return 1;
    }

    if(sum < 0 || n == 0){
        return 0;
    }
    return cntRecur(coins, n, sum - coins[n-1]) + cntRecur(coins, n-1, sum);
}

int count(vector<int> &coins, int sum){
    return cntRecur(coins, coins.size(), sum);
}

int main(){
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << count(coins, sum);
    return 0;
}