#include<bits/stdc++.h>
using namespace std;

int editDistMemo(string& s1, string& s2, int m, int n, vector<vector<int>> &memo){
    if(m == 0){
        return n;
    }
    if(n == 0){
        return m;
    }

    if(memo[m][n] != -1){
        return memo[m][n];
    }

    if(s1[m-1] == s2[n-1]){
        return memo[m][n] = editDistMemo(s1, s2, m-1, n-1, memo);
    }

    return memo[m][n] = 1 + min({editDistMemo(s1, s1, m, n-1, memo),
                                editDistMemo(s1, s2, m-1, n, memo),
                                editDistMemo(s1, s2, m-1, n-1, memo)});
}

int editDist(string& s1, string& s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
    return editDistMemo(s1, s2, m, n, memo);
}

int main(){
    string s1 = "geeks";
    string s2 = "geeks";
    cout << editDist(s1, s2);
    return 0;
}