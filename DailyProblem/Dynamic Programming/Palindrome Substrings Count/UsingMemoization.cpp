#include<bits/stdc++.h>
using namespace std;

int isPalindrome(int i, int j, string& s, vector<vector<int>>& memo){
    if(i==j){
        return 1;
    }

    if(j==i+1 && s[i]==s[j]){
        return 1;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }
    memo[i][j] = (s[i] == s[j] && isPalindrome(i+1, j-1, s, memo));
    return memo[i][j];
}

int countPS(string& s){
    int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isPalindrome(i, j, s, memo)){
                res++;
            }
        }
    }
    return res;
}

int main(){
    string s = "abaab";
    cout<<countPS(s);
    return 0;
}