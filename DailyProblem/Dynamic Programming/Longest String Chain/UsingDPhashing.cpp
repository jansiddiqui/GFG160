#include<bits/stdc++.h>
using namespace std;

bool static cmp(const string &a, const string& b){
    return a.size() < b.size();
}

int lsc(vector<string>& words){
    sort(words.begin(), words.end(), cmp);
    unordered_map<string, int> dp;
    int res = 1;

    for(const string& w : words){
        dp[w] = 1;
        for(int i=0;i<w.size();++i){
            string pred = w.substr(0, i) + w.substr(i+1);
            if(dp.find(pred) != dp.end()){
                dp[w] = max(dp[w], dp[pred] + 1);
            }
        }
        res = max(res, dp[w]);
    }
    return res;
}

int main(){
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout<<lsc(words)<<endl;
    return 0;
}