#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> &arr){
    int res = 0, n = arr.size();
    for(int i=0;i<n;i++){
        int curr = arr[i];
        for(int j=i-1;j>=0 && arr[j] >= arr[i];j--){
            curr += arr[i];
        }
        for(int j=i+1;j<n && arr[j] >= arr[i]; j++){
            curr += arr[i];
        }
        res = max(res, curr);
    }
    return res;
}
int main(){
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr);
    return 0;
}