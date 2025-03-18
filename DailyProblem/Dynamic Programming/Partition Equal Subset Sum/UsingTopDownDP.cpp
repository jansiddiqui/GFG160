#include<bits/stdc++.h>
using namespace std;
//Memoization
bool isSubsetSum(int n, vector<int>& arr, int sum, vector<vector<int>> &memo){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(memo[n-1][sum] != -1){
        return memo[n-1][sum];
    }
    if(arr[n-1] > sum){
        return isSubsetSum(n-1, arr, sum, memo);
    }
    return memo[n-1][sum] = isSubsetSum(n-1, arr, sum, memo) || isSubsetSum(n-1, arr, sum-arr[n-1], memo);
}
bool equalPartition(vector<int>& arr){
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum%2 !=0){
        return false;
    }
    vector<vector<int>> memo(arr.size(), vector<int>(sum+1, -1));
    return isSubsetSum(arr.size(), arr, sum/2, memo);
}

int main(){
    vector<int> arr = {1,5,6};
    if(equalPartition(arr)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}