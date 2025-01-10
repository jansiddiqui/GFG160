#include<bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> res;

    for(int i=0;i<=n-k;i++){
        unordered_set<int> st;
        for(int j=i;j<i+k;j++){
            st.insert(arr[j]);
        }
        res.push_back(st.size());
    }
    return res;
}
int main(){
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> res = countDistinct(arr, k);
    for(int ele: res){
        cout<<ele<<" ";
    }
    return 0;
}