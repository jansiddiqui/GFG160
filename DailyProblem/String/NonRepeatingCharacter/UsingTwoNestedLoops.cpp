#include<bits/stdc++.h>
using namespace std;

char nonReapeatingChar(string &s){
    int n = s.length();
    for(int i = 0; i<n; ++i){
        bool found = false;

        for(int j=0; j<n; ++j){
            if(i != j && s[i] == s[j]){
                found = true;
                break;
            }
        }
        if(found == false){
            return s[i];
        }
    }
    return '$';
}

int main(){
    string s = "racecar";
    cout<<nonReapeatingChar(s);
    return 0;
}