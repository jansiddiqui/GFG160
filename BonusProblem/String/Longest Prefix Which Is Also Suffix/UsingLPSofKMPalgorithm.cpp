#include<bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string s){
    int n = s.length();
    vector<int> lps(n);

    int len = 0;

    lps[0] = 0;

    int i = 1;
    while(i < s.length()){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[n - 1];
}
int main(){
    string s = "bcafafbc";
    cout<<longestPrefixSuffix(s);
    return 0;
}