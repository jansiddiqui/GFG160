#include<bits/stdc++.h>
using namespace std;

int countWays(string &digits){
    int n = digits.length();
    vector<int> dp(n+1, 0);
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        if(digits[i] != '0'){
            dp[i] = dp[i+1];
        }
        if((i+1 < n) && ((digits[i] == '1' && digits[i+1] <= '9') || (digits[i] == '2' && digits[i+1] <= '6'))){
            dp[i] += dp[i+2];
        }
    }
    return dp[0];
}
int main(){
    string digits = "121";
    cout << countWays(digits);
    return 0;
}