#include<bits/stdc++.h>
using namespace std;

void permutations(vector<vector<int>>& res, vector<int>& curr, int idx);

void nextPermutation(vector<int>& arr){
    vector<vector<int>> res;
    permutations(res, arr, 0);
    sort(res.begin(), res.end());
    for(int i=0;i<res.size();i++){
        if(res[i]==arr){
            if(i<res.size() - 1){
                arr = res[i + 1];
            }
            if(i == res.size() - 1){
                arr = res[0];
            }
            break;
        }
    }
}

void permutations(vector<vector<int>>& res, vector<int>& arr, int idx){
    if(idx == arr.size() - 1){
        res.push_back(arr);
        return;
    }
    for(int i=idx;i<arr.size();i++){
        swap(arr[idx], arr[i]);
        permutations(res, arr, idx + 1);
        swap(arr[idx], arr[i]);
    }
}
int main(){
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    nextPermutation(arr);

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}