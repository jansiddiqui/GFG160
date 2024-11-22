#include<bits/stdc++.h>
using namespace std;

int maximumProfit(const vector<int>& prices){
    int res = 0;

    for(int i=1; i<prices.size(); i++){
        if(prices[i]>prices[i-1]){
            res += prices[i]-prices[i-1];
        }
    }
    return res;
}
int main(){
    vector<int> prices = { 100, 180, 260, 310, 40, 535, 695};
    cout<<maximumProfit(prices)<<endl;
    return 0;
}