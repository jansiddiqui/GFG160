#include<bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string s){
    int res = 0;
    int n = s.length();

    for(int len=1;len<n;len++){
        int i = 0;
        int j = s.length() - len;
        bool flag  = true;

        for(int k=0;k<len;k++){
            if(s[i + k] != s[j + k]){
                flag = false;
                break;
            }
        }
        if(flag){
            res = len;
        }

    }
    return res;
}
int main(){
    string s = "ababab";
    cout<<longestPrefixSuffix(s);
    return 0;
}