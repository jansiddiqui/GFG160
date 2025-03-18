#include<bits/stdc++.h>
using namespace std;

bool equalPartition(vector<int>& arr){
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();

    if(sum%2 != 0){
        return false;
    }

    sum = sum/2;
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for(int i =0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1] [j - arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> arr = {1, 2, 3};
    if(equalPartition(arr)){
        cout<<"True"<<endl;
    }
    else{
        cout << "False"<<endl;
    }
    return 0;
}