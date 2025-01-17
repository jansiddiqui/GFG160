#include<bits/stdc++.h>
using namespace std;

vector<int> prodExceptSelf(vector<int>& arr){
    int n = arr.size();
    vector<int> res(n, 1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j){
                res[i] *= arr[j];
            }
        }
    }
    return res;
}

int main(){
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = prodExceptSelf(arr);
    for(int val : res){
        cout<<val<<" ";
    }
    return 0;
}