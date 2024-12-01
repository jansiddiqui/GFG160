#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

char nonRepeatingChar(string &s){
    vector<int> freq(MAX_CHAR, 0);

    for(char c : s){
        freq[c - 'a']++;
    }

    for(int i=0; i<s.length(); ++i){
        if(freq[s[i] - 'a'] == 1){
            return s[i];
        }
    }
    return '$';
}

int main(){
    string s = "mohammad";
    cout<<nonRepeatingChar(s);
    return 0;
}