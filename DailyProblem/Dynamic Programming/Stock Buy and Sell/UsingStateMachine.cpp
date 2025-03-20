#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices){
    int firstBuy = INT_MIN;
    int firstSell = 0;
    int secondBuy = INT_MIN;
    int secondSell = 0;

    for(int i=0;i<prices.size();i++){
        firstBuy = max(firstBuy, -prices[i]);
        firstSell = max(firstSell, firstBuy + prices[i]);
        secondBuy = max(secondBuy, firstSell - prices[i]);
        secondSell = max(secondSell, secondBuy + prices[i]);
    }
    return secondSell;
}

int main(){
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout<<maxProfit(prices);
    return 0;
}