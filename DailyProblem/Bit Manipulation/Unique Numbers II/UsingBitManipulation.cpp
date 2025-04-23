#include<bits/stdc++.h>
using namespace std;

vector<int> singleNum(vector<int>& arr){
    int xorVal = 0;
    for(auto i : arr){
        xorVal = i ^ xorVal;
    }

    xorVal &= -xorVal;
    vector<int> ans(2, 0);
    for(int num : arr){
        if((num & xorVal) == 0){
            ans[0] ^= num;
        }
        else{
            ans[1] ^= num;
        }
    }
    if(ans[0] > ans[1]){
        swap(ans[0], ans[1]);
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,2,1,4};
    vector<int> ans = singleNum(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}