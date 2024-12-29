#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target){
    unordered_map<int, int> freq;
    int cnt = 0;

    for(int i=0;i<arr.size();i++){
        if(freq.find(target - arr[i]) != freq.end()){
            cnt += freq[target - arr[i]];
        }
        freq[arr[i]]++;
    }
    return cnt;
}
int main(){
    vector<int> arr = {1, 3, 4, 2, 5};
    int target = 5;
    cout<<countPairs(arr, target);
    return 0;
}