#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int n, vector<int>& arr, int sum){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(arr[n-1] > sum){
        return isSubsetSum(n-1, arr, sum);
    }
    return isSubsetSum(n-1, arr, sum) || isSubsetSum(n-1, arr, sum - arr[n-1]);
}
bool equalPartition(vector<int> & arr){
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum % 2 != 0){
        return false;
    }
    return isSubsetSum(arr.size(), arr, sum/2);
}
int main(){
    vector<int> arr = {1,5,11,5};
    if(equalPartition(arr)){
        cout << "True"<<endl;
    }else{
        cout<<"False" << endl;
    }
    return 0;
}