#include<bits/stdc++.h>
using namespace std;

int lps(const string &s){
    int n = s.size();
    vector<int> curr(n), prev(n);
    for(int i=n-1;i>=0;--i){
        curr[i] = 1;
        for(int j=i+1;j<n;j++){
            if(s[i] == s[j]){
                curr[j] = prev[j-1] + 2;
            }else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    return curr[n-1];
}
int main(){
    string s = "bbabcbcab";
    cout<<lps(s);
    return 0;
}