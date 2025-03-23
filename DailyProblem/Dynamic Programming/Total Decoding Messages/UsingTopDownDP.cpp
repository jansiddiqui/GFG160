#include<bits/stdc++.h>
using namespace std;

int decodeHelper(string &digits, int idx, vector<int> &memo){
    int n = digits.length();
    if(idx >= n){
        return 1;
    }
    if(memo[idx] != -1){
        return memo[idx];
    }
    int ways = 0;
    if(digits[idx] != '0'){
        ways = decodeHelper(digits, idx+1, memo);
    }
    if((idx + 1 < n) && ((digits[idx] == '1' && digits[idx + 1] <= '9') || (digits[idx] == '2' && digits[idx + 1] <= '6'))){
        ways += decodeHelper(digits, idx + 2, memo);
    }
    memo[idx] = ways;
    return ways;
}
int countWays(string &digits){
    int n = digits.length();
    vector<int> memo(n, -1);
    return decodeHelper(digits, 0, memo);
}
int main(){
    string digits = "121";
    cout << countWays(digits);
    return 0;
}