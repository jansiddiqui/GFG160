#include<bits/stdc++.h>
using namespace std;

int minPF(vector<int> &arr, vector<int> &dep){
    int n = arr.size();
    int res = 0;

    int maxDep = dep[0];
    for(int i=1;i<n;i++){
        maxDep = max(maxDep, dep[i]);
    }

    vector<int> v(maxDep+2, 0);

    for(int i=0;i<n;i++){
        v[arr[i]]++;
        v[dep[i]+1]--;
    }

    int cnt = 0;

    for(int i=0;i<=maxDep+1;i++){
        cnt += v[i];
        res = max(res, cnt);
    }
    return res;
}
int main(){
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<minPF(arr, dep);
    return 0;
}