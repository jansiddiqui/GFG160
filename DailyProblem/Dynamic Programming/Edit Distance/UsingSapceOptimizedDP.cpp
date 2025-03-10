#include<bits/stdc++.h>
using namespace std;

int editDist(string& s1, string& s2){
    int m = s1.size();
    int n = s2.size();

    vector<int> prev(n+1, 0), curr(n+1, 0);

    for(int j=0;j<=n;j++){
        prev[j] = j;
    }

    for(int i=1;i<=m;i++){
        curr[0] = i;
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                curr[j] = 1 + min({curr[j-1], prev[j], prev[j-1]});
            }
        }
        prev = curr;
    }
    return prev[n];
}
int main(){
    string s1 = "jan";
    string s2 = "kan";

    cout << editDist(s1, s2);
    return 0;
}