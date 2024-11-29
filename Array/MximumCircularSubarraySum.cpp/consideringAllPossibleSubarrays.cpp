#include<bits/stdc++.h>
using namespace std;

int circularSubarraySum(vector<int> &arr){
    int n = arr.size();
    int res = arr[0];

    for(int i=0;i<n;i++){
        int currSum = 0;
        for(int j=0;j<n;j++){
            int idx = (i + j) % n;
            currSum = currSum + arr[idx];
            res = max(res, currSum);
        }
    }
    return res;
}

int main(){
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout<<circularSubarraySum(arr);
}