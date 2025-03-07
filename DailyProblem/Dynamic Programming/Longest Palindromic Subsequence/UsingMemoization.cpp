#include<bits/stdc++.h>
using namespace std;

int lps(const string& s, int low, int high, vector<vector<int>> &memo){
    if(low > high) return 0;
    if(low == high){
        return 1;
    }
    if(memo[low][high] != -1){
        return memo[low][high];
    }
    if(s[low] == s[high]){
        return memo[low][high] = lps(s, low+1, high-1, memo) + 2;
    }
    return memo[low][high] = max(lps(s, low, high - 1, memo), lps(s, low + 1, high, memo));
}
int longestPalSubstr(string &s){
    vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
    return lps(s, 0, s.size() - 1, memo);
}
int main(){
    string s = "bbabcbcab";
    int n = s.size();
    cout<<longestPalSubstr(s);
    return 0;
}