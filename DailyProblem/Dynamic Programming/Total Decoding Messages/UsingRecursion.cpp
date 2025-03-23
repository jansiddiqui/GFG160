#include<bits/stdc++.h>
using namespace std;

int decodeHelper(string &digits, int idx){
    int n = digits.length();
    if(idx >= n){
        return 1;
    }
    int ways = 0;
    if(digits[idx] != '0'){
        ways = decodeHelper(digits, idx+1);
    }
    if((idx+1<n) && ((digits[idx] == '1' && digits[idx+1] <= '9') || (digits[idx] == '2' && digits[idx + 1] <= '6'))){
        ways += decodeHelper(digits, idx + 2);
    }
    return ways;
}

int countWays(string &digits){
    return decodeHelper(digits, 0);
}
int main(){
    string digits = "121";
    cout << countWays(digits);
    return 0;
}