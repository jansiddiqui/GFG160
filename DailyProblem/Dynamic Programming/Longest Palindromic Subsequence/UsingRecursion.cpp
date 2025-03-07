#include<bits/stdc++.h>
using namespace std;

int lps(const string& s, int low, int high){
    if(low > high) return 0;
    if(low == high){
        return 1;
    }
    if(s[low] == s[high]){
        return lps(s, low+1, high-1) + 2;
    }
    return max(lps(s, low, high-1), lps(s, low+1, high));
}

int longestPalinSubseq(string &s){
    return lps(s, 0, s.size()-1);
}
int main(){
    string s = "bbabcbcab";
    // int n = s.size();
    cout << longestPalinSubseq(s) << endl;
    return 0;
}