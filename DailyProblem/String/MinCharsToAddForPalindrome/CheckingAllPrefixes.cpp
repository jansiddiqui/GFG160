#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minChar(string &s){
    int count = 0;
    int i = s.size() - 1;

    while(i >= 0 && !isPalindrome(s, 0, i)){
        i--;
        count++;
    }
    return count;
}

int main(){
    string s = "aacdcaaaaa";
    cout<<minChar(s);
    return 0;
}