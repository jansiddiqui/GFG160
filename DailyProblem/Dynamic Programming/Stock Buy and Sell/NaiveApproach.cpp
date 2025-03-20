#include<bits/stdc++.h>
using namespace std;

int maxProfOne(vector<int> &prices, int idx){
    int minSoFar = prices[idx], res = 0;
    for(int i=idx+1; i<prices.size();i++){
        minSoFar = min(minSoFar, prices[i]);
        res = max(res, prices[i] - minSoFar);
    }
    return res;
}
int maxProfit(vector<int>& prices){
    int n = prices.size();
    int minSoFar = prices[0], res = 0;

    for(int i=1;i<n;i++){
        if(prices[i] > minSoFar){
            int curr = prices[i] - minSoFar + maxProfOne(prices, i);
            res = max(res, curr);
        }else{
            minSoFar = min(minSoFar, prices[i]);
        }
    }
    return res;
}
int main(){
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(prices);
    return 0;
}