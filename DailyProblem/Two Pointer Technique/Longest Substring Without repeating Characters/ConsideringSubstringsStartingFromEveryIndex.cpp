#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

int longestUniqueSubstr(string& s){
    int n = s.size();
    int res = 0;

    for(int i = 0; i<n; i++){
        vector<bool> vis(MAX_CHAR, false);
        for(int j=i;j<n;j++){
            if(vis[s[j] - 'a'] == true){
                break;
            }
            else{
                res = max(res, j - i + 1);
                vis[s[j] - 'a'] = true;
            }
        }
    }
    return res; 
}
int main(){
    string s = "geeksforgeeks";
    cout<<longestUniqueSubstr(s);
    return 0;
}