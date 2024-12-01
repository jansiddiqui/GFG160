#include<bits/stdc++.h>
using namespace std;

bool areAnagrams(string &s1, string &s2){
    unordered_map<char, int> charCount;
    for(char ch:s1){
        charCount[ch] += 1;
    }
    for(char ch:s2){
        charCount[ch] -= 1;
    }
    for(auto& pair : charCount){
        if(pair.second != 0){
            return false;
        }
    }
    return true;
}
int main(){
    string s1 = "listen";
    string s2 = "silnt";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;
    return 0;
}