#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string &s, vector<string> &dictionary){
    int n = s.size();
    vector<bool> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(string &w : dictionary){
            int start = i - w.size();
            if(start >= 0 && dp[start] && s.substr(start, w.size()) == w){
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}

int main(){
    string s = "hijan";
    vector<string> dictionary = {"hi", "jan", "hi", "leet"};
    cout << (wordBreak(s, dictionary) ? "true" : "false");
    return 0;
}