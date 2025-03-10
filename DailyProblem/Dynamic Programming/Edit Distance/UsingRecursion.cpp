#include<bits/stdc++.h>
using namespace std;

int editDistanceRec(string& s1, string& s2, int m, int n){
    if(m == 0){
        return n;
    }
    if(n == 0){
        return m;
    }
    if(s1[m-1] == s2[n-1]){
        return editDistanceRec(s1, s2, m-1, n-1);
    }

    return 1 + min({editDistanceRec(s1, s2, m, n-1), 
                    editDistanceRec(s1, s2, m-1, n),
                    editDistanceRec(s1, s2, m-1, n-1)});
}

int editDistance(string& s1, string& s2){
    return editDistanceRec(s1, s2, s1.size(), s2.size());
}

int main(){
    string s1 = "abcd";
    string s2 = "bcfe";

    cout << editDistance(s1, s2);
    return 0;
}