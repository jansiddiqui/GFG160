#include<bits/stdc++.h>
using namespace std;

int countPalindromes(string& s){
    int n = s.size();
    int count = 0;

    for(int i=0;i<n;i++){
        int left=i-1;
        int right=i+1;
        while(left >=0 and right < n){
            if(s[left] == s[right])
                count++;
            else
                break;
            left--;
            right++;
        }
    }

    for(int i=0;i<s.size();i++){
        int left = i;
        int right = i+1;
        while(left >= 0 and right < n){
            if(s[left] == s[right])
                count++;
            else
                break;
            left--;
            right++;
        }
    }
    return count;
}

int main(){
    string s = "abbaeae";
    cout<<countPalindromes(s);
    return 0;
}