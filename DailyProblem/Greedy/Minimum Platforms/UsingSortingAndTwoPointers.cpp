#include<bits/stdc++.h>
using namespace std;

int minPF(vector<int> &arr, vector<int>&dep){
    int n = arr.size();
    int res = 0;

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int j = 0;
    int cnt = 0;
    
    for(int i =0;i<n;i++){
        while(j<n && dep[j] <arr[i]){
            cnt--;
            j++;
        }
        cnt++;
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