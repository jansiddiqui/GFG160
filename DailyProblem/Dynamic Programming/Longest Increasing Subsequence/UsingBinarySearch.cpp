#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr){
    int n = arr.size();
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int low = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[low] = arr[i];
        }
    }
    return ans.size();
}

int main(){
    vector<int> arr = {1,2,5, 7, 0,7, 3};
    printf("Length of LTS is %d\n", lis(arr));
    return 0;
}