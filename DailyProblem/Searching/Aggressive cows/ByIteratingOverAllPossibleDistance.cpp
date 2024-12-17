#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &stalls, int k, int dist) {
    
    int cnt = 1;  
    int prev = stalls[0]; 
    for (int i = 1; i < stalls.size(); i++) {
        
        if (stalls[i] - prev >= dist) {
            prev = stalls[i]; 
            cnt++; 
        }
    }

    return (cnt >= k);
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int res = 0; 
    int minDist = 1;
    int maxDist = stalls.back() - stalls[0];  

    for (int i = minDist; i <= maxDist; i++) {
        
        if (check(stalls, k, i))
            res = i;  
    }

    return res;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << ans;
    return 0;
}