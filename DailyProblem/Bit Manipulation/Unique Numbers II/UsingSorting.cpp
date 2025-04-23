#include<bits/stdc++.h>
using namespace std;

vector<int> singleNum(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> ans;
    int i=0;
    while(i<n){
        if(i+1<n && arr[i] == arr[i+1]){
            i += 2;
        }else{
            ans.push_back(arr[i]);
            i++;
        }
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