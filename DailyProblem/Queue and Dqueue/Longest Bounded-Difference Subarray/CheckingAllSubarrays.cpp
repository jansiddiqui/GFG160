#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubarray(vector<int>& arr, int x){
    int n=arr.size();
    int beginning = 0, maxLen = 1;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int mini = INT_MAX, maxi = INT_MIN;
            for(int k=i;k<=j;k++){
                mini = min(mini, arr[k]);
                maxi = max(maxi, arr[k]);
            }
            if(maxi-mini <= x && maxLen < j-i+1){
                maxLen = j-i+1;
                beginning = i;
            }
        }
    }

    vector<int> res;
    for(int i=beginning;i<beginning+maxLen;i++){
        res.push_back(arr[i]);
    }
    return res;

}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int x = 3;
    vector<int> res = longestSubarray(arr, x);
    for(auto val : res){
        cout << val << " ";
    }
    return 0;
}