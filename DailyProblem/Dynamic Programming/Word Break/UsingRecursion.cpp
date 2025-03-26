#include<bits/stdc++.h>
using namespace std;

bool wordBreakRec(int i, string &s, vector<string> &dictionary){
    int n = s.length();
    if(i == n){
        return true;
    }

    string prefix = "";

    for(int j = i;j<n;j++){
        prefix += s[j];
        if(find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end() && wordBreakRec(j+1, s, dictionary)){
            return true;
        }
    }
    return false;
}
bool wordBreak(string &s, vector<string> &dictionary){
    return wordBreakRec(0, s, dictionary);
}
int main(){
    string s = "ilike";
    vector<string > dictionary = {"i", "like", "gfg"};
    cout << (wordBreak(s, dictionary) ? "true" : "false");
    return 0;
}