#include<bits/stdc++.h>
using namespace std;

bool areAnagrams(string &s1, string &s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}
int main(){
    string s1 = "Good";
    string s2 = "Gdoo";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}