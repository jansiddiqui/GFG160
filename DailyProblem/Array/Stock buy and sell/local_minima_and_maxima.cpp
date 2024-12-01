#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int lMin = 0, lMax = 0;
    int res = 0;

    int i = 0;
    while (i < n - 1) {
        // Find the local minima (buying point)
        while (i < n - 1 && prices[i] >= prices[i + 1]) {
            i++;
        }
        lMin = prices[i];

        // Find the local maxima (selling point)
        while (i < n - 1 && prices[i] <= prices[i + 1]) {
            i++;
        }
        lMax = prices[i];

        // Add the profit from this transaction
        res += lMax - lMin;
    }
    return res;
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << "Maximum Profit: " << maximumProfit(prices) << endl;
    return 0;
}
