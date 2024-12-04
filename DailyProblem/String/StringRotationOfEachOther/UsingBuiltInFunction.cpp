#include<bits/stdc++.h>
using namespace std;

bool areRotations(string &s1, string &s2){
    s1 += s2;
    return s1.find(s2) != string::npos;
}
int main(){
    string s1 = "abcde", s2 = "cdeab";

    cout<<(areRotations(s1, s2) ? "true" : "false");
}