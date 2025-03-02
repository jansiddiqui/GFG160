#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int> &arr, int k){
    int n = arr.size();

    vector<int> res;

    for(int i=0;i<=n-k;i++){
        int max = arr[i];
        for(int j=1;j<k;j++){
            if(arr[i+j] > max){
                max = arr[i+j];
            }
        }
        res.push_back(max);
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,3,1,4,5,2,3,6};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for(int maxVal : res){
        cout<<maxVal<<" ";
    }
    return 0;
}