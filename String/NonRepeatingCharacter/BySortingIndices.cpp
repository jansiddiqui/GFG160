#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

char nonRepeatingChar(string s){
    vector<int> vis(MAX_CHAR, -1);
    for(int i=0; i<s.length();i++){
        if(vis[s[i] - 'a'] == -1){
            vis[s[i]- 'a'] = i;
        }
        else{
            vis[s[i] - 'a'] = -2;
        }
    }
    int idx = INT_MAX;
    for(int i=0; i<MAX_CHAR; i++){
        if(vis[i] >= 0){
            idx = min(idx, vis[i]);
        }
    }
    return (idx == INT_MAX ? '$' : s[idx]);
}

int main(){
    string s = "aabbc";
    cout<<nonRepeatingChar(s)<<endl;
    return 0;
}