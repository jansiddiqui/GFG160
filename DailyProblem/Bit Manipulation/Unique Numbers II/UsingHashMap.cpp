#include<bits./stdc++.h>
using namespace std;

vector<int> singleNum(vector<int>& arr){
    unordered_map<int, int> freq;

    for(int x : arr){
        freq[x]++;
    }
    vector<int> ans;
    
    for(const auto& p : freq){
        if(p.second == 1){
            ans.push_back(p.first);
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