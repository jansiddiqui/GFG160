#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k){
    unordered_map<int, int> mp;
    int res = 0;
    int prefSum = 0;

    for(int i = 0; i<arr.size(); ++i){
        prefSum += arr[i];

        if(prefSum == k){
            res = i + 1;
        }
        else if(mp.find(prefSum - k) != mp.end()){
            res = max(res, i - mp[prefSum - k]);
        }
        if(mp.find(prefSum) == mp.end()){
            mp[prefSum] = i;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << longestSubarray(arr, k) << endl;
    return 0;
}