#include<bits/stdc++.h>
using namespace std;

int minRepeats(string &s1, string &s2){
    int n = s1.length(), m = s2.length();

    for(int i=0;i<n;i++){
        int rep = 1, idx1 = i;
        bool found = true;

        for(int idx2=0;idx2<m;idx2++){
            if(s1[idx1] != s2[idx2]){
                found = false;
                break;
            }
            idx1++;

            if(idx1 == n){
                idx1 = 0;

                if(idx2 != m-1){
                    rep++;
                }
            }
        }
        if(found){
            return rep;
        }
    }
    return -1;
}

int main(){
    string s1 = "abcd";
    string s2 = "cdabcdab";

    cout<<minRepeats(s1, s2);
    return 0;
}