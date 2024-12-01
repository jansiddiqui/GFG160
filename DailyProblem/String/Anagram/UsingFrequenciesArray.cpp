#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

bool areAnagrams(string &s1, string &s2){
    vector<int> freq(MAX_CHAR, 0);

    for(char ch:s1){
        freq[ch - 'a']++;
    }

    for(char ch:s2){
        freq[ch - 'a']--;
    }

    for(int count : freq){
        if(count != 0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "mango";
    string s2 = "goman";
    cout<<(areAnagrams(s1, s2) ? "true" : "false") << endl;
    return 0;
}