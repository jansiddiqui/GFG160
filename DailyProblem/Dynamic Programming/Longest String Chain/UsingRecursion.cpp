#include<bits/stdc++.h>
using namespace std;

bool  isPred(const string  &a, const string &b){
    if(a.size() != b.size() + 1) return false;
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        if(a[i] ==b[j]) {i++; j++;}
        else{i++;}
    }
    return (j == b.size());
}

int longestEndCurr(vector<string> &words, string &curr){
    int maxEnd = 1;
    for(string &w : words){
        if(isPred(curr, w)){
            maxEnd = max(maxEnd, 1+longestEndCurr(words, w));
        }
    }
    return maxEnd;
}

// longestStringChain
int lsc(vector<string> &words){
    int res = 1;
    for(string &w : words){
        res = max(res, longestEndCurr(words, w));
    }
    return res;
}

int main(){
    vector<string> s = {"a", "b", "ba", "bca","bda", "bdca"};
    cout<<lsc(s);
    return 0;
}