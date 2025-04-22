#include<bits/stdc++.h>
using namespace std;

int findUnique(vector<int> &arr){
    int  n = arr.size();
    unordered_map<int, int> cnt;
    for(int i=0;i<n;i++){
        cnt[arr[i]]++;
    }
    for(auto p : cnt){
        if(p.second == 1){
            return p.first;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {2,3,5,4,5,3,4};
    cout<<findUnique(arr);
    return 0;
}