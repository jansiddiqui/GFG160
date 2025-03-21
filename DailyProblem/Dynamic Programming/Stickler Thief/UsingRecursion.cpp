#include<bits/stdc++.h>
using namespace std;

int maxLootRec(vector<int> &arr, int n){
    if(n <= 0) return 0;

    if(n == 1) return arr[0];

    int pick = arr[n-1] + maxLootRec(arr, n-2);
    int notPick = maxLootRec(arr, n-1);

    return max(pick, notPick);
}

int findMaxSum(vector<int>&arr){
    int n = arr.size();
    return maxLootRec(arr, n);
}

int main(){
    vector<int> arr = {6, 5, 5, 7, 4};
    cout << findMaxSum(arr);
    return 0;
}