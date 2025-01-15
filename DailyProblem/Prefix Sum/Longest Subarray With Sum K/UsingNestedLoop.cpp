#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k){
    int res = 0;

    for(int i=0;i<arr.size();i++){
        int sum = 0;
        for(int j = i; j<arr.size();j++){
            sum += arr[j];
            if(sum == k){
                int subLen = j - i + 1;
                res = max(res, subLen);
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << longestSubarray(arr, k)<<endl;
    return 0;
}