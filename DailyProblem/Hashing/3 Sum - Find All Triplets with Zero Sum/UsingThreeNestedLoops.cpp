#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr){
    vector<vector<int>> res;
    int n = arr.size();
    
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    res.push_back({i, j, k});
                }
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> res = findTriplets(arr);
    for(int i=0;i<res.size();i++){
        cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
    }
    return 0;
}